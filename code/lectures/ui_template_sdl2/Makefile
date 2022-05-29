TARGET = ui_template_sdl2
BUILD_DIR ?= cmake-build-debug
CMAKE = cmake

ifeq ($(OS),Windows_NT)
	FLAGS = -DCMAKE_SH="CMAKE_SH-NOTFOUND" -G "MinGW Makefiles"
else
	FLAGS = ""
endif

all: clean reload build exec

run: reload build exec

mkdir_build:
	[ -d ./$(BUILD_DIR) ] | mkdir -p $(BUILD_DIR)

build:
	cd $(BUILD_DIR);$(CMAKE) --build . --target $(TARGET)

exec:
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

reload: mkdir_build
	cd $(BUILD_DIR);$(CMAKE) $(FLAGS) ..
