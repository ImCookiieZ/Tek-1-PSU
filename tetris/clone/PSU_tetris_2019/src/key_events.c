/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** key_events.c
*/

#include "../include/all_includes.h"

int my_key_left(char **ar, game *info)
{
    int x = info->cur->pos_x;
    int y = info->cur->pos_y;
    int my_do = TRUE;

    for (int i = 0; i < info->cur->type.size_y; i++) {
        if (x + get_first_letter(info->cur->type.array, LINE, i,
            LEFT) == 0 || ar[y + i][x + get_first_letter (info->cur->type
            .array, LINE, i, LEFT) - 1] != ' ')
            my_do = FALSE;
    }
    if (my_do == TRUE)
        change_position(ar, info, -1, 0);
    return (0);
}

int my_key_right(char **ar, game *info)
{
    int x = info->cur->pos_x;
    int y = info->cur->pos_y;
    int my_do = TRUE;

    for (int i = 0; i < info->cur->type.size_y; i++) {
        if (ar[y + i][x + info->cur->type.size_x - 1 - get_first_letter
        (info->cur->type.array, LINE, i, RIGHT) + 1] != ' ')
            my_do = FALSE;
    }
    if (my_do == TRUE)
        change_position(ar, info, 1, 0);
    return (0);
}

int key_drop(char **ar, game *info)
{
    int lowest_down = info->max_rows;
    int cur_down = 1;
    int y = 0;

    for (int x = 0; x < info->cur->type.size_x; x++) {
        y = info->cur->pos_y + info->cur->type.size_y - get_first_letter
            (info->cur->type.array, COLUMN, x, DOWN);
        while (ar[y + cur_down] && ar[y + cur_down][x + info->cur->pos_x] ==
        ' ')
            cur_down++;
        if (cur_down < lowest_down)
            lowest_down = cur_down;
        cur_down = 0;
    }
    change_position(ar, info, 0, lowest_down);
    return (SUCCESS);
}