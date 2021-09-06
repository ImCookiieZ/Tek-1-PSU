/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int new_tetri(game *info, char **ar)
{
    info->cur = malloc(sizeof(game_tetri));
    info->cur->type.size_y = info->next->type.size_y;
    info->cur->type.size_x = info->next->type.size_x;
    info->cur->type.color = info->next->type.color;
    info->cur->type.error = info->next->type.error;
    info->cur->type.name = info->next->type.name;
    info->cur->type.array = malloc(sizeof(char *) * (info->cur->type
        .size_y + 1));
    for (int i = 0; i < info->cur->type.size_y; i++)
        info->cur->type.array[i] = my_strdup(info->next->type.array[i]);
    info->cur->type.array[info->cur->type.size_y] = NULL;
    info->cur->pos_y = info->next->pos_y;
    info->cur->pos_x = info->next->pos_x;
    for (int i = 0; info->next->type.array[i]; i++)
        free(info->next->type.array[i]);
    free(info->next->type.array);
    free(info->next);
    info->next = NULL;
    return (check_loose(info, ar));
}

int check_loose(game *info, char **ar)
{
    int x = info->cur->pos_x;
    int y = info->cur->pos_y;

    for (int i = 0; i < info->cur->type.size_y; i++) {
        for (int j = 0; j < info->cur->type.size_x; j++) {
            if (info->cur->type.array[i][j] != ' ' && ar[y + i][x + j] != ' ')
                return (FALSE);
        }
    }
    return (RUNNING);
}

int check_ground(char **ar, game *info)
{
    int y = 0;

    if (info->cur == NULL)
        return (FALSE);
    for (int x = 0; x < info->cur->type.size_x; x++) {
        y = info->cur->pos_y + info->cur->type.size_y -
            get_first_letter(info->cur->type.array, COLUMN, x, DOWN);
        if (!(y >= 0 && ar[y] && ar[y][x + info->cur->pos_x] == ' '))
            return (TRUE);
    }
    return (FALSE);
}

int my_delete_line(char **ar, int line)
{
    for (int i = 0; ar[line][i]; i++)
        ar[line][i] = ' ';
    for (int i = line - 1; i >= 0; i--)
        for (int j = 0; ar[i][j]; j++)
            if (ar[i][j] != ' ') {
                ar[i + 1][j] = ar[i][j];
                ar[i][j] = ' ';
            }
    return (1);
}

int check_lines(game *info, char **ar)
{
    static int counter = 0;
    int line = TRUE;
    for (int i = 0; ar[i]; i++) {
        for (int j = 0; ar[i][j] && line == TRUE; j++)
            if (ar[i][j] == ' ')
                line = FALSE;
        if (line == TRUE) {
            counter += my_delete_line(ar, i);
            info->score += 10;
            i--;
        }
        line = TRUE;
    }
    if (info->score > info->highscore) info->highscore = info->score;
    if (counter == 10) {
        counter = 0;
        info->level++;
    }
    for (int i = 0; info->cur->type.array[i]; i++)
        free(info->cur->type.array[i]);
    return (SUCCESS);
}