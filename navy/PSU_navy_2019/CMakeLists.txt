cmake_minimum_required(VERSION 3.15)
project(PSU_navy_2019 C)

set(CMAKE_C_STANDARD 99)

file (GLOB lib_dir
        "lib/my/*.c")

add_executable(PSU_navy_2019 ${lib_dir} src/connect.c src/display.c src/error.c
        src/main.c src/gameloop.c src/signal_handling.c src/shoot.c)