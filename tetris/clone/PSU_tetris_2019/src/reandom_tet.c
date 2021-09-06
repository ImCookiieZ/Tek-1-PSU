/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** reandom_tet.c
*/

#include "../include/all_includes.h"

int get_turn(game *info, int randi, int randj)
{
    info->next = malloc(sizeof(game_tetri));
    info->next->type = info->tetri[randj];
    while (info->next->type.error != 0) {
        randj = rand() % info->count_tetri;
        info->next->type = info->tetri[randj];
    }
    info->next->pos_x = (info->max_cols - info->next->type.size_x) / 2;
    info->next->pos_y = 0;
    info->next->type.array = malloc(sizeof(char *) * (info->next->type
        .size_y + 1));
    for (int i = 0; i < info->next->type.size_y; i++)
        info->next->type.array[i] = my_strdup(info->tetri[randj].array[i]);
    info->next->type.array[info->next->type.size_y] = NULL;
    for (int i = 0; i < randi; i++)
        begin_turn(info);
    begin_turn(info);
    return (0);
}

void switch_arrays2(char **new, game *info)
{
    int new_x = 0;
    int new_y = 0;
    int mid_x = (info->next->type.size_x - 1) / 2;
    int mid_y = (info->next->type.size_y - 1) / 2;

    new[info->next->type.size_x] = NULL;
    for (int i = 0; info->next->type.array[i]; i++) {
        for (int j = 0; info->next->type.array[i][j]; j++) {
            new_x = (mid_x - (i) + mid_y) - (mid_x - (info->next->type.size_y
                - 1 - mid_y));
            new_y = (mid_y + (j) - mid_x) - (mid_y - mid_x);
            if (info->next->type.array[i][j] == ' ') new[new_y][new_x] = ' ';
            else new[new_y][new_x] = (char) (info->next->type.color + '0');
        }
        free(info->next->type.array[i]);
    }
    free(info->next->type.array);
    for (int i = 0; i <info->next->type.size_x; i++)
        for (int j = 0; j < info->next->type.size_y; j++)
            if (new[i][j] < '0' || new[i][j] > '7') new[i][j] = ' ';
    info->next->type.array = new;
}

int begin_turn(game *info)
{
    char **new = malloc(sizeof(char *) * (info->next->type.size_x + 1));
        if (new == NULL) my_error_exit("malloc failed\n");
    for (int i = 0; i < info->next->type.size_x; i++) {
        new[i] = malloc(sizeof(char) * (info->next->type.size_y + 1));
        if (new[i] == NULL) my_error_exit("malloc failed\n");
        for (int j = 0; j < info->next->type.size_y; new[i][j] = ' ', j++);
        new[i][info->next->type.size_y] = '\0';
    }
    switch_arrays2(new, info);
    my_swap(&info->next->type.size_y, &info->next->type.size_x);
    return (0);
}