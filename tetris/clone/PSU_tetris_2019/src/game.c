/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game.c
*/

#include "../include/all_includes.h"

int create_new_tetri(game *info, char **ar)
{
    int randi = rand() % 4;
    int randj = rand() % info->count_tetri;
    if (info->pause == FALSE) {
        color_set(1, 0);
        mvhline((info->max_rows - 7) / 2 + 6, 3, 0, 24);
        mvhline((info->max_rows - 7) / 2 + 17, 3, 0, 24);
        mvvline((info->max_rows - 7) / 2 + 7, 2, 0, 10);
        mvvline((info->max_rows - 7) / 2 + 7, 27, 0, 10);
        mvaddch((info->max_rows - 7) / 2 + 6, 2, ACS_DIAMOND);
        mvaddch((info->max_rows - 7) / 2 + 6, 27, ACS_DIAMOND);
        mvaddch((info->max_rows - 7) / 2 + 17, 27, ACS_DIAMOND);
        mvaddch((info->max_rows - 7) / 2 + 17, 2, ACS_DIAMOND);
        color_set(7, 0);
        if (info->next == NULL) {
            clear();
            get_turn(info, randi, randj);
        }
        else if (info->cur == NULL)
            return (new_tetri(info, ar));
    }
    return (RUNNING);
}

int change_position(char **ar, game *info, int change_x, int change_y)
{
    int x = info->cur->pos_x;
    int y = info->cur->pos_y;

    for (int i = 0; info->cur->type.array[i]; i++) {
        for (int j = 0; info->cur->type.array[i][j]; j++) {
            if (info->cur->type.array[i][j] != ' ')
                ar[y + i][x + j] = ' ';
        }
    }
    y += change_y;
    x += change_x;
    for (int i = 0; info->cur->type.array[i]; i++) {
        for (int j = 0; info->cur->type.array[i][j]; j++) {
            if (info->cur->type.array[i][j] != ' ')
                ar[y + i][x + j] = (char) (info->cur->type.color + '0');
        }
    }
    info->cur->pos_x += change_x;
    info->cur->pos_y += change_y;
    return (RUNNING);
}

char *get_input(char *input_c)
{
    free(input_c);
    input_c = malloc(sizeof(char) * 4096);
    input_c = my_memset(input_c, 4096, 0);
    for (int i = 0; 1; i++) {
        input_c[i] = getch();
        if (input_c[i] == ERR) {
            input_c[i] = 0;
            break;
        }
    }
    return (input_c);
}

void gameloop(char *input_c, game *info, char **game_array)
{
    long tmp_time = 0;
    for (; create_new_tetri(info, game_array) == RUNNING; print_extras(info)) {
        input_c = get_input(input_c);
        if (info->pause) info->pause_time = clock() - info->start_pause_time;
        info->gametime = clock() - info->starttime - info->tmp_pause;
        if (info->gametime > tmp_time && info->cur && info->pause == FALSE) {
            tmp_time = info->gametime + 1000000 - info->level * 10000;
            change_position(game_array, info, 0, 1);
        }
        if (my_strlen(input_c) > 0) key_event(game_array, input_c, info);
        if (info->pause == FALSE) {
            my_put_color(game_array);
            display_interface(info->gametime, info->max_rows, info->max_cols);
            if (check_ground(game_array, info) == TRUE) {
                check_lines(info, game_array);
                free(info->cur->type.array);
                free(info->cur);
                info->cur = NULL;
            }
        }
    }
}

int game_f(game *info)
{
    char *input_c = malloc(1);
    char **game_array = prepare_2d_char_array(info->max_cols,
        info->max_rows);

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    gameloop(input_c, info, game_array);
    for (int i = 0; game_array[i]; i++)
        free(game_array[i]);
    free(game_array);
    return (SUCCESS);
}