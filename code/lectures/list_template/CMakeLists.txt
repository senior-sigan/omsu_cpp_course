cmake_minimum_required(VERSION 3.15)
project(list_project_template C)

set(CMAKE_C_STANDARD 11)

add_executable(list_project_template
        main.c
#        linked_list.c
        array_list.c
)