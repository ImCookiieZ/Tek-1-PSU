cmake_minimum_required(VERSION 3.15)
project(PSU_minishell1_2019 C)

set(CMAKE_C_STANDARD 99)

file (GLOB lib_dir
        "lib/my/*.c")

add_executable(PSU_minishell1_2019 ${lib_dir} src/main.c src/prepare.c
        lib/my/my_strcap.c src/my_env.c "src/split_input.c" src/my_fork.c src/new_word_array.c src/if_trees.c src/my_cd.c)