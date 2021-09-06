/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** TODO: add description
*/

#include "../include/my_sokoban.h"

int check_x(char **map, int i, int j)
{
    int runable = 0;

    if ((map[i + 1][j] == '#' || map[i + 1][j] == 'X') && \
    (map[i][j + 1] == '#' || map[i][j + 1] == 'X'))
        runable++;
    if ((map[i + 1][j] == '#' || map[i + 1][j] == 'X') && \
    (map[i][j + 1] == '#' || map[i][j + 1] == 'X'))
        runable++;
    if ((map[i - 1][j] == '#' || map[i - 1][j] == 'X') && \
    (map[i][j + 1] == '#' || map[i][j + 1] == 'X'))
        runable++;
    if ((map[i - 1][j] == '#' || map[i - 1][j] == 'X') && \
    (map[i][j - 1] == '#' || map[i][j - 1] == 'X'))
        runable++;
    if (runable >= 1) {
        return (0);
    }
    return (1);
}

int check_runable(char **map)
{
    int runable = 0;

    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'X')
                runable += check_x(map, i, j);
        }
    if (runable == 0) {
        endwin();
        exit(1);
    }
    return (0);
}

int check_boxes(int i, int j, int **o_s)
{
    for (int k = 0; o_s[k] != NULL; k++) {
        if (o_s[k][0] == i && o_s[k][1] == j)
            return (1);
    }
    return (0);

}

int *get_player(char **map, int *player, int **o_s)
{
    int ret = 1;

    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'X' && ret == 1)
                ret = check_boxes(i, j, o_s);
            else if (map[i][j] == 'P') {
                player[0] = i;
                player[1] = j;
            }
        }
    if (ret == 1) {
        endwin();
        exit(0);
    }
    else if (player[0] != -1 || player[1] != -1)
        return (player);
    endwin();
    write(2, "no player found\n", 16);
    exit(84);
}