/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void my_exit(game *info, char **game_array, char *input_c)
{
    for (int i = 0; i < info->cur->type.size_y; i++)
        free(info->cur->type.array[i]);
    for (int i = 0; i < info->next->type.size_y; i++)
        free(info->next->type.array[i]);
    free(info->cur->type.array);
    free(info->next->type.array);
    free(info->ctrl.pause);
    free(info->ctrl.quit);
    free(info->ctrl.turn);
    free(info->ctrl.right);
    free(info->ctrl.left);
    free(info->ctrl.drop);
    if (info->next) {
        for (int i = 0; info->next->type.array[i]; i++)
            free(info->next->type.array[i]);
        free(info->next->type.array);
    }
    if (info->cur) {
        for (int i = 0; info->cur->type.array[i]; i++)
            free(info->cur->type.array[i]);
        free(info->next->type.array);
    }
    for (int i = 0; i < info->count_tetri; i++) {
        free(info->tetri[i].name);
        if (info->tetri[i].error == TRUE) continue;
        for (int j = 0; info->tetri[i].array[j]; j++)
            free(info->tetri[i].array[j]);
        free(info->tetri[i].array);
    }
    for (int i = 0; game_array[i]; i++) free(game_array[i]);
    free(game_array);
    free(input_c);
}

int pause_or_quit(char *input, game *info, char **game_array)
{
    if (my_strcmp(input, info->ctrl.quit) == 0) {
        endwin();
        my_printf("you exited with %s", input);
        my_exit(info, game_array, input);
        return (84);
    }
    if (my_strcmp(input, info->ctrl.pause) == 0) {
        if (info->pause == FALSE) {
            info->pause = TRUE;
            info->start_pause_time = clock();
        }
        else {
            info->pause = FALSE;
            info->gametime -= info->pause_time;
        }
        return (4);
    }
    return (0);
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
    return (pause_or_quit(input, info, ar));
}
