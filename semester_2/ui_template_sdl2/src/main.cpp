#include <SDL.h>

#include <algorithm>
#include <cmath>
#include <iostream>

static void PANIC_SDL_ERROR(const std::string &msg) {
  SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s error: %s", msg.c_str(), SDL_GetError());
  exit(-1);
}

static SDL_Rect CalcSizes(SDL_Texture *tex, SDL_Renderer *ren) {
  SDL_Rect dst = {0, 0, 0, 0};
  SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);

  int sw, sh;
  SDL_GetRendererOutputSize(ren, &sw, &sh);

  auto rw = static_cast<float>(sw) / dst.w;
  auto rh = static_cast<float>(sh) / dst.h;
  auto r = static_cast<int>(std::floor(std::min(rw, rh)));

  dst.w *= r;
  dst.h *= r;

  return dst;
}

struct RGBA {
  const unsigned char red;
  const unsigned char green;
  const unsigned char blue;
  const unsigned char alpha;
};

const auto RED = RGBA{255, 0, 0, 0};
const auto GREEN = RGBA{0, 255, 0, 0};
const auto BLUE = RGBA{0, 0, 255, 0};
const auto BLACK = RGBA{0, 0, 0, 0};
const auto WHITE = RGBA{255, 255, 255, 0};

union RGBA_flatten {
  RGBA rgba_;
  unsigned int value;
};

union RGBA_unflatten {
  unsigned int value;
  RGBA rgba_;
};

int main() {
  auto canvas_width = 160;
  auto canvas_height = 90;

  SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    PANIC_SDL_ERROR("SDL_Init");
  }

  auto win = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED_DISPLAY(0u), SDL_WINDOWPOS_CENTERED_DISPLAY(0u), 640, 360,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (!win) {
    PANIC_SDL_ERROR("SDL_CreateWindow");
  }

  auto render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!render) {
    PANIC_SDL_ERROR("SDL_CreateRenderer");
  }

  auto texture =
      SDL_CreateTexture(render, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, canvas_width, canvas_height);
  if (!texture) {
    PANIC_SDL_ERROR("SDL_CreateTexture");
  }

  auto canvas = new unsigned int[static_cast<unsigned int>(canvas_width * canvas_height)];
  for (auto i = 0; i < canvas_height * canvas_width; i++) {
    if (i % 3 == 0) {
      canvas[i] = RGBA_flatten{RED}.value;
    } else if (i % 3 == 1) {
      canvas[i] = RGBA_flatten{GREEN}.value;
    } else {
      canvas[i] = RGBA_flatten{BLUE}.value;
    }
  }

  SDL_Event event;
  auto isRunning = true;
  while (isRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT || event.type == SDL_APP_TERMINATING) {
        isRunning = false;
      }
      auto dstrect = CalcSizes(texture, render);

      SDL_RenderClear(render);
      SDL_UpdateTexture(texture, nullptr, canvas, canvas_width * 4);
      SDL_RenderCopy(render, texture, nullptr, &dstrect);
      SDL_RenderPresent(render);
    }
  }

  delete[] canvas;
  return 0;
}
