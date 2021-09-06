/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

const char *header[58] = {
    "1 1 1 1 1  2 2 2 2 2  3 3 3 3 3  4 4 4 4 4  5  6 6 6 6 6\n",
    "    1      2              3      4       4     6        \n",
    "    1      2 2 2          3      4 4 4 4    5  6 6 6 6 6\n",
    "    1      2              3      4     4    5          6\n",
    "    1      2 2 2 2 2      3      4       4  5  6 6 6 6 6\n"};

void color_switch(int row, int col, char color)
{
    if (color > '0' && color < '7') {
        color_set(color - '0', 0);
        mvprintw(row, col, "*");
        color_set(7, 0);
    } else
        mvprintw(row, col, "%c", color);
}

int print_around(game *info)
{
    int biggest = 0;
    for (int i = 0; i < info->count_tetri; i++) {
        if (info->tetri[i].error == FALSE) {
            if (info->tetri[i].size_y > biggest)
                biggest = info->tetri[i].size_y;
            if (info->tetri[i].size_x > biggest)
                biggest = info->tetri[i].size_x;
        }
    }
    color_set(1, 0);
    mvhline(12, info->max_cols + 36, 0, biggest + 2);
    mvhline(13 + biggest + 2, info->max_cols + 36, 0, biggest + 2);
    mvvline(13, info->max_cols + 35, 0, biggest + 2);
    mvvline(13, info->max_cols + 38 + biggest, 0, biggest + 2);
    mvaddch(13 + biggest + 2, info->max_cols + 38 + biggest, ACS_DIAMOND);
    mvaddch(13 + biggest + 2, info->max_cols + 35, ACS_DIAMOND);
    mvaddch(12, info->max_cols + 35, ACS_DIAMOND);
    mvaddch(12, info->max_cols + 38 + biggest, ACS_DIAMOND);
    color_set(7, 0);
    for (int i = 0; info->next && info->next->type.array[i]; i++) {
        for (int j = 0; info->next->type.array[i][j]; j++)
            if (info->next->type.array[i][j] != ' ')
                color_switch(14 + i + (biggest - info->next->type.size_y) / 2,
                    j + info->max_cols + 37 + (biggest - info->next->type
                    .size_x) / 2,
                    (char) (info->next->type.color + '0'));
    }
    return (0);
}

int print_extras(game *info)
{
    print_around(info);
    mvprintw((info->max_rows - 7) / 2 + 7, 3, "Score:");
    mvprintw((info->max_rows - 7) / 2 + 7, 20, "%d", info->score);
    mvprintw((info->max_rows - 7) / 2 + 8, 3, "High Score:");
    mvprintw((info->max_rows - 7) / 2 + 8, 20, "%d", info->highscore);
    if (info->hide_next == TRUE) {
        refresh();
        return (0);
    }
    mvprintw(10, info->max_cols + 35, "next");
    mvprintw(11, info->max_cols + 35, "tetramino:");
    refresh();
    return (0);
}

void my_put_color(char **array)
{
    for (int i = 0; array[i]; i += 1)
        for (int j = 0; array[i][j]; j += 1)
            color_switch(i + 7, j + 31, array[i][j]);
}

void display_header(int max_cols)
{
    for (int i = 0; header[i]; i += 1)
        for (int j = 0; header[i][j]; j += 1)
            color_switch(i, j + (max_cols / 2) + 5, header[i][j]);
}