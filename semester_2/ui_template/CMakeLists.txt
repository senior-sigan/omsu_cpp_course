cmake_minimum_required(VERSION 3.0)
project(ui)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_subdirectory(lib/raylib-master)

add_executable(ui main.cpp)
target_link_libraries(ui raylib_static)