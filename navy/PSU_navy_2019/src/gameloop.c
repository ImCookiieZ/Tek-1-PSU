/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** gameloop.c
*/

#include "../include/all_includes.h"

void hit(int data)
{
    int letter = 0;
    int nb = 0;

    for (; data > 8; data -= 8, nb++);
    letter = (char) data;
    gv->enemy_map[nb][letter - 1] = 'x';
    my_printf("%c%c: hit\n", letter + 'A' - 1, nb + '0' + 1);
    if (check_game_over(gv->enemy_map) != -1)
        gv->win = ME;
    else {
        if (gv->server == 0)
            display_game(gv->my_map, gv->enemy_map);
        else
            my_printf("\n");
        my_printf("%s", "waiting for enemy's attack...\n");
    }
}

void missed(int data)
{
    int letter = 0;
    int nb = 0;

    for (; data > 8; data -= 8, nb++);
    letter = (char) data;
    if (gv->enemy_map[nb][letter - 1] != 'x')
        gv->enemy_map[nb][letter - 1] = 'o';
    my_printf("%c%c: missed\n", letter + 'A' - 1, nb + '0' + 1);
    if (gv->server == 0)
        display_game(gv->my_map, gv->enemy_map);
    else
        my_printf("\n");
    my_printf("%s", "waiting for enemy's attack...\n");
}

int check_game_over(char **hidden_enem_array)
{
    int counter = 0;

    for (int i = 0; hidden_enem_array[i]; i += 1)
        for (int j = 0; hidden_enem_array[i][j]; j += 1)
            if (hidden_enem_array[i][j] == 'x')
                counter += 1;
    if (counter < 14)
        return (-1);
    return (1);
}

int gameloop(void)
{
    if (gv->server == 0)
        display_game(gv->my_map, gv->enemy_map);
    if (gv->status) {
        my_printf("%s", "waiting for enemy's attack...\n");
        get_enemy_shot();
    }
    while (gv->win == -1) {
        if (gv->server) display_game(gv->my_map, gv->enemy_map);
        if (player_turn() == 84)
            return (84);
    }
    return (gv->win);
}