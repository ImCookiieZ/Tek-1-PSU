/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** preparation.c
*/

#include "../include/all_includes.h"

void display_time(clock_t gametime, int x)
{
    int seconds = (int) (gametime / 1000000) % 60;
    int minutes = (int) (gametime / 1000000) / 60;

    mvprintw((x - 7) / 2 + 10, 3, "Time:");
    mvprintw((x - 7) / 2 + 10, 20, "%02d:%02d", minutes, seconds);
}

char **prepare_2d_char_array( int x, int y)
{
    char **dest = malloc(sizeof(char *) * (y + 1));
    if (dest == NULL)
        my_error_exit("malloc failed");
    for (int i = 0; i < y; i++) {
        dest[i] = malloc(sizeof(char) * (x + 1));
        if (dest[i] == NULL)
            my_error_exit("malloc failed");
        for (int j = 0; j < x; j++)
            dest[i][j] = ' ';
        dest[i][x] = 0;
    }
    dest[y] = NULL;
    return (dest);
}

void display_interface(clock_t gametime, int map_y, int map_x)
{
    color_set(1, 0);
    mvhline(7, 31, 0, map_x * 2);
    mvhline(7 + map_y, 31, 0, map_x * 2);
    mvvline(8, 30, 0, map_y - 1);
    mvvline(8, 31 + map_x * 2, 0, map_y);
    mvaddch(7, 31 + map_x * 2, ACS_URCORNER);
    mvaddch(7, 30, ACS_ULCORNER);
    mvaddch(7 + map_y, 31 + map_x * 2, ACS_LRCORNER);
    mvaddch(7 + map_y, 30, ACS_LLCORNER);
    color_set(7, 0);
    display_time(gametime, map_y);
    display_header(map_x);
}