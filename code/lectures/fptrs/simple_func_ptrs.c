#include <stdio.h>

void hello(void) {
  printf("Hello\n");
}

void world(void) {
  printf("World\n");
}

int main() {
  void (*func)(void) = hello;

  hello();
  world();
  func();

  return 0;
}
