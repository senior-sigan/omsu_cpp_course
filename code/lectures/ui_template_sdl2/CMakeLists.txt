cmake_minimum_required(VERSION 3.15)
project(ui_template_sdl2)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wfloat-equal -Wno-unused-private-field -Wunused-parameter -Wsign-conversion -Wold-style-cast -Wno-unused-const-variable")

find_package(SDL2 REQUIRED)
message(STATUS ${SDL2_LIBRARY})
include_directories(${SDL2_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})