/*
** EPITECH PROJECT, 2020
** generator
** File description:
** error.c
*/

#include "../include/all_includes.h"

void my_put_error_str(char *str)
{
    int i;
    for (i = 0; str[i]; i++);
    write(2, "\033[31m", 5);
    write(2, str, i);
    write(2, "\033[0m", 4);
}

void my_error_exit(char *error_msg)
{
    my_put_error_str(error_msg);
    exit(84);
}

int check_buffer(char *buffer)
{
    if (buffer == NULL || buffer[0] == '\0')
        return (1);
    for (int i = 0; buffer[i] ; i += 1)
        if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '*' &&
            buffer[i] != ' ' && buffer[i] != '\n')
            return (1);
    return (0);
}

int check_tetri(tetrimino *tetri, char *buffer, game *info)
{
    if (tetri->size_x < 1 || tetri->size_x >= info->max_cols || tetri->size_y
        < 1 || tetri->size_y >= info->max_rows)
        tetri->error = 1;
    if (tetri->color < 1 || tetri->color > 7)
        tetri->error = 1;
    for (int i = 0; buffer[i] ; i += 1)
        if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '*' &&
        buffer[i] != ' ' && buffer[i] != '\n')
            tetri->error = 1;
    return (tetri->error);
}