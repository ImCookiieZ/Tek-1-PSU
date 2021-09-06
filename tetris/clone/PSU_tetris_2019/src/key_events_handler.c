/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int check_resize(game *info)
{
    int biggest = 0;
    int mx = 0;
    int my = 0;
    getmaxyx(stdscr, my, mx);
    biggest = get_big(info);
    if (mx < info->max_cols * 2 + 38 + biggest * 2 + 1 || my < info->max_rows
    + 8) {
        info->pause = TRUE;
        info->size = TRUE;
        clear();
        mvprintw(0, 0, "resize terminal");
    }
    else if (info->size == TRUE) {
        info->pause = FALSE;
        info->size = FALSE;
        clear();
    }
    return (0);
}

int pause_or_quit(char *input, game *info)
{
    if (my_strcmp(input, info->ctrl.quit) == 0) {
        for (int i = 0; info->cur->type.array[i]; i++)
            free(info->cur->type.array[i]);
        free(info->cur->type.array);
        endwin();
        my_printf("you exited with %s", input);
        exit(0);
    }
    if (my_strcmp(input, info->ctrl.pause) == 0) {
        if (info->pause == FALSE) {
            info->pause = TRUE;
            info->start_pause_time = clock();
        }
        else {
            info->pause = FALSE;
            info->gametime -= info->pause_time;
            info->tmp_pause += info->pause_time;
        }
        return (4);
    }
    return (check_resize(info));
}

int key_event(char **ar, char *input, game *info)
{
    if (info->pause == FALSE) {
        if (my_strcmp(input, info->ctrl.left) == 0) {
            my_key_left(ar, info);
            return (2);
        }
        if (my_strcmp(input, info->ctrl.drop) == 0) {
            key_drop(ar, info);
            return (7);
        }
        if (my_strcmp(input, info->ctrl.right) == 0) {
            my_key_right(ar, info);
            return (3);
        }
        if (my_strcmp(input, info->ctrl.turn) == 0) {
            key_turn(ar, info);
            return (6);
        }
    }
    return (pause_or_quit(input, info));
}
