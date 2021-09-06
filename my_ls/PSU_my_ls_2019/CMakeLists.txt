cmake_minimum_required(VERSION 3.15)
project(PSU_my_ls_2019 C)

set(CMAKE_C_STANDARD 99)

file (GLOB lib_dir
        "lib/my/*.c")
file (GLOB src_dir
        "src/main.c"
        "src/error_handling.c"
        "src/my_only_ls.c")

add_executable(PSU_my_ls_2019 ${lib_dir} ${src_dir} src/ls_l.c src/ls_r.c src/ls_t.c src/ls_d.c src/ls_cr.c include/all_includes.h)