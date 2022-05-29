.PHONY: all clean

PROJECT_NAME       ?= game
RAYLIB_PATH        ?= lib/raylib-2.6.0
BUILD_MODE         ?= RELEASE
EXT 			   ?= .exe
PLATFORM           ?= PLATFORM_DESKTOP
BUILD_DIR          ?= build

# Use Wayland display server protocol on Linux desktop
# by default it uses X11 windowing system
USE_WAYLAND_DISPLAY   ?= FALSE

CC = g++
LANGUAGE_VERSION = c++11

INCLUDE_PATHS = -I. -I$(RAYLIB_PATH)/include

# Define compiler flags:
#  -O1                  defines optimization level
#  -g                   include debug information on compilation
#  -s                   strip unnecessary data from build
#  -Wall                turns on most, but not all, compiler warnings
#  -std=c99             defines C language mode (standard C from 1999 revision)
#  -std=gnu99           defines C language mode (GNU C from 1999 revision)
#  -Wno-missing-braces  ignore invalid warning (GCC bug 53119)
#  -D_DEFAULT_SOURCE    use with -std=c99 on Linux and PLATFORM_WEB, required for timespec
CFLAGS += -O1 -Wall -std=$(LANGUAGE_VERSION) -Wno-missing-braces

ifeq ($(BUILD_MODE),DEBUG)
    CFLAGS += -g
endif

# Determine PLATFORM_OS
# No uname.exe on MinGW!, but OS=Windows_NT on Windows!
# ifeq ($(UNAME),Msys) -> Windows
ifeq ($(OS),Windows_NT)
	PLATFORM_OS=WINDOWS
else
	UNAMEOS=$(shell uname)
	UNAME_P := $(shell uname -p)

	ifeq ($(UNAMEOS),Linux)
		PLATFORM_OS=LINUX
		ifeq ($(UNAME_P),x86_64)
			ARCHITECTURE = -amd64
		endif
		ifneq ($(filter %86,$(UNAME_P)),)
			ARCHITECTURE = -i386
		endif
	endif
	ifeq ($(UNAMEOS),Darwin)
		PLATFORM_OS=OSX
	endif
endif

ifeq ($(PLATFORM_OS),WINDOWS)
    # Libraries for Windows desktop compilation
    # NOTE: WinMM library required to set high-res timer resolution
    LDLIBS = -lopengl32 -lgdi32 -lwinmm
    # Required for physac examples
    #LDLIBS += -static -lpthread
endif
ifeq ($(PLATFORM_OS),LINUX)
    # Libraries for Debian GNU/Linux desktop compiling
    # NOTE: Required packages: libegl1-mesa-dev
    LDLIBS = -lGL -lm -lpthread -ldl -lrt
    
    # On X11 requires also below libraries
    LDLIBS += -lX11
    # NOTE: It seems additional libraries are not required any more, latest GLFW just dlopen them
    #LDLIBS += -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
endif
ifeq ($(PLATFORM_OS),OSX)
    # Libraries for OSX 10.9 desktop compiling
    # NOTE: Required packages: libopenal-dev libegl1-mesa-dev
    LDLIBS = -framework OpenGL -framework OpenAL -framework Cocoa -framework IOKit -framework CoreVideo
endif

# LDFLAGS = -L. -L$(RAYLIB_PATH)/lib
LIBS = $(RAYLIB_PATH)/$(PLATFORM_OS)$(ARCHITECTURE)/libraylib.a

OBJS = main.cpp

all: build

prepare:
	mkdir -p $(BUILD_DIR)

build: prepare $(OBJS)
	$(CC) -o $(BUILD_DIR)/$(PROJECT_NAME)$(EXT) $(OBJS) $(LIBS) $(CFLAGS) $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS)

run:
	./$(BUILD_DIR)/$(PROJECT_NAME)$(EXT)

clean:
	rm -rf $(BUILD_DIR)