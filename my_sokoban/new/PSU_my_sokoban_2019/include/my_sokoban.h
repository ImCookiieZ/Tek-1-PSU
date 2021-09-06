/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** TODO: add description
*/

#ifndef PSU_MY_SOKOBAN_2019_MY_SOKOBAN_H
#define PSU_MY_SOKOBAN_2019_MY_SOKOBAN_H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/my.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **process_map(char **map, int const *player, int const *ar);
char get_input(char **map, char *buffer, int *ar);
int check_size(int const *ar);
int my_error_checker(char *buffer);
void run_function(char *buffer, int len);
int game(char **map, int **o_s, char *buffer, int *ar);
char **game_print(char **map, int **);
int my_error_print(char *av);
int my_open(char *file, int size);
int check_x(char **map, int i, int j);
int check_runable(char **map);
int *get_player(char **map, int *player, int **);
#endif //PSU_MY_SOKOBAN_2019_MY_SOKOBAN_H
