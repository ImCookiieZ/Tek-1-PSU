/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** TODO: add description
*/

#include "../include/my_sokoban.h"

char **my_process_input(char **map, int mover, int *player)
{
    int ar[2] = {0, 0};

    if (mover == 's' || mover == 'B')
        ar[0] = 1;
    if (mover == 'w' || mover == 'A')
        ar[0] = -1;
    if (mover == 'a' || mover == 'D')
        ar[1] = -1;
    if (mover == 'd' || mover == 'C')
        ar[1] = 1;
    map = process_map(map, player, ar);
    return (map);
}

char **process_map_cx(char **map, int const *player, int const *ar)
{
    char my_tmp = 0;

    if (map[player[0] + ar[0] * 2][player[1] + ar[1] * 2] != '#') {
        if (map[player[0] + ar[0] * 2][player[1] + ar[1] * 2] == 'X')
            return (map);
        else if (map[player[0] + ar[0] * 2][player[1] + ar[1] * 2] == ' ' \
        || map[player[0] + ar[0] * 2][player[1] + ar[1] * 2] == 'O') {
            my_tmp = map[player[0] + ar[0] * 2][player[1] + ar[1] * 2];
            map[player[0]][player[1]] = ' ';
            map[player[0] + ar[0]][player[1] + ar[1]] = 'P';
            map[player[0] + ar[0] * 2][player[1] + ar[1] * 2] = 'X';
        }
    }
    return (map);
}

char **process_map(char **map, int const *player, int const *ar)
{
    char my_tmp = 0;

    if (map[player[0] + ar[0]][player[1] + ar[1]] != '#') {
        if (map[player[0] + ar[0]][player[1] + ar[1]] == 'X')
            map = process_map_cx(map, player, ar);
        else if (map[player[0] + ar[0]][player[1] + ar[1]] == ' ' \
        || map[player[0] + ar[0]][player[1] + ar[1]] == 'O') {
            map[player[0]][player[1]] = ' ';
            map[player[0] + ar[0]][player[1] + ar[1]] = 'P';
        }
    }
    return (map);
}

int game(char **map, int **o_s, char *buffer, int *ar)
{
    int *player = malloc(sizeof(int) * 2);
    int mover = 0;

    player[0] = -1;
    player[1] = -1;
    check_runable(map);
    player = get_player(map, player, o_s);
    mover = get_input(map, buffer, ar);
    map = game_print(map, o_s);
    if (mover != 0)
        map = my_process_input(map, mover, player);
    map = game_print(map, o_s);
    free(player);
    game(map, o_s, buffer, ar);
    return (0);
}

char **game_print(char **map, int **coordinates)
{
    for (int i = 0; coordinates[i]; i++) {
        if (map[coordinates[i][0]][coordinates[i][1]] == ' ') {
            map[coordinates[i][0]][coordinates[i][1]] = 'O';
        }
    }
    for (int i = 0; map[i]; i++) {
        mvprintw(i, 0, "%s", map[i]);
    }
    refresh();
    return (map);
}