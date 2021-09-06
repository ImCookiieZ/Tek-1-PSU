cmake_minimum_required(VERSION 3.15)
project(test_clock C)

set(CMAKE_C_STANDARD 99)
link_libraries(csfml-graphics)
link_libraries(csfml-system)
add_executable(test_clock main.c)