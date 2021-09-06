/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

char **set_char(char **ar, game *info, char c)
{
    int x = info->cur->pos_x;
    int y = info->cur->pos_y;

    for (int i = 0; info->cur->type.array[i]; i++) {
        for (int j = 0; info->cur->type.array[i][j]; j++) {
            if (info->cur->type.array[i][j] != ' ')
                ar[y + i][x + j] = c;
        }
    }
    return (ar);
}

void switch_arrays(char **new, game *info)
{
    int new_x = 0;
    int new_y = 0;
    int mid_x = (info->cur->type.size_x - 1) / 2;
    int mid_y = (info->cur->type.size_y - 1) / 2;

    new[info->cur->type.size_x] = NULL;
    for (int i = 0; info->cur->type.array[i]; i++) {
        for (int j = 0; info->cur->type.array[i][j]; j++) {
            new_x = (mid_x - (i) + mid_y) - (mid_x - (info->cur->type.size_y
                - 1 - mid_y));
            new_y = (mid_y + (j) - mid_x) - (mid_y - mid_x);
            if (info->cur->type.array[i][j] == ' ') new[new_y][new_x] = ' ';
            else new[new_y][new_x] = (char) (info->cur->type.color + '0');
        }
        free(info->cur->type.array[i]);
    }
    free(info->cur->type.array);
    for (int i = 0; i <info->cur->type.size_x; i++)
        for (int j = 0; j < info->cur->type.size_y; j++)
            if (new[i][j] < '0' || new[i][j] > '7') new[i][j] = ' ';
    info->cur->type.array = new;
}

int check_valid_change(game *info, char **ar)
{
    int new_x = 0;
    int new_y = 0;
    int mid_x = (info->cur->type.size_x - 1) / 2;
    int mid_y = (info->cur->type.size_y - 1) / 2;
    int change_y = mid_y - mid_x;
    int change_x = (info->cur->type.size_x - info->cur->type.size_y) / 2;

    for (int i = 0; info->cur->type.array[i]; i++) {
        for (int j = 0; info->cur->type.array[i][j]; j++) {
            new_x = (mid_x - (i) + mid_y) - (mid_x - (info->cur->type.size_y
                - 1 - mid_y));
            new_y = (mid_y + (j) - mid_x) - (mid_y - mid_x);
            if (info->cur->pos_y + change_y + new_y < 0 || change_x + new_x +
            info->cur->pos_x < 0 || info->cur->pos_y + change_y + new_y
            >= info->max_rows || info->cur->pos_x + change_x +
            new_x >= info->max_cols || ar[info->cur->pos_y + change_y +
            new_y][change_x + new_x + info->cur->pos_x] != ' ')
                return (FALSE);
        }
    }
    return (TRUE);
}

int key_turn(char **ar, game *info)
{
    char **new = malloc(sizeof(char *) * (info->cur->type.size_x + 1));
    int change_x = (info->cur->type.size_x - info->cur->type.size_y) / 2;
    if (new == NULL) my_error_exit("malloc failed\n");
    ar = set_char(ar, info, ' ');
    if (check_valid_change(info, ar) == FALSE) {
        ar = set_char(ar, info, (char) (info->cur->type.color + '0'));
        return (ERROR);
    }
    for (int i = 0; i < info->cur->type.size_x; i++) {
        new[i] = malloc(sizeof(char) * (info->cur->type.size_y + 1));
        if (new[i] == NULL) my_error_exit("malloc failed\n");
        for (int j = 0; j < info->cur->type.size_y; new[i][j] = ' ', j++);
        new[i][info->cur->type.size_y] = '\0';
    }
    switch_arrays(new, info);
    my_swap(&info->cur->type.size_y, &info->cur->type.size_x);
    change_position(ar, info,  change_x, 0);
    return (0);
}
