/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** shoot.c
*/

#include "../include/all_includes.h"

void send_shoot(char const *coordinates)
{
    int letter = coordinates[0] - 'A';
    int nb = coordinates[1] - '0';
    int ret = -1;

    ret = (nb - 1) * 8 + letter + 1;
    send_signal(SHOT, ret);
    gv->status = YOU;
    usleep(8000);
}

void get_enemy_shot(void)
{
    while (gv->status == YOU)
        if (gv->win == -1)
            usleep(1000);
        else
            return;
    check_game_over(gv->my_map) == 1 ? gv->win = YOU : -1;
}

int check_hit(int const *coordinates)
{
    int ret = MISSED;
    if (gv->my_map[coordinates[1]][coordinates[0]] != '.' &&
    gv->my_map[coordinates[1]][coordinates[0]] != 'o' &&
    gv->my_map[coordinates[1]][coordinates[0]] != 'x') {
        gv->my_map[coordinates[1]][coordinates[0]] = 'x';
        ret = HIT;
    }
    else if (gv->my_map[coordinates[1]][coordinates[0]] != 'x')
        gv->my_map[coordinates[1]][coordinates[0]] = 'o';
    send_signal(ret, coordinates[1] * 8 + coordinates[0] + 1);
    usleep(10000);
    my_printf(": ");
    ret == HIT ? my_printf("hit\n") : my_printf("missed\n");
    return (ret);
}

void receive_shoot(int data)
{
    int *coordinates = malloc(sizeof(char) * 3);
    int letter = 0;
    int nb = 0;

    if (!(coordinates))
        return;
    for (; data > 8; data -= 8, nb++);
    letter = (char) data;
    coordinates[0] = letter - 1;
    coordinates[1] = nb;
    coordinates[2] = 0;
    my_putchar(coordinates[0] + 'A');
    my_putchar(coordinates[1] + '0' + 1);
    check_hit(coordinates);
    gv->status = ME;
}

int player_turn(void)
{
    int len = 0;
    size_t buffsize = 0;
    char *buffer = NULL;

    gv->server ? my_printf("%s", "attack: ") : my_printf("%s", "\nattack: ");
    len = getline(&buffer, &buffsize, stdin);
    if (len == -1) return (84);
    if (len == 3) buffer[len - 1] = '\0';
    buffer = my_strcapitalize(buffer);
    while (check_input(buffer) != 0) {
        my_putstr("wrong position\nattack: ");
        len = getline(&buffer, &buffsize, stdin);
        if (len == -1) return (84);
        if (len == 3) buffer[len - 1] = '\0';
        buffer = my_strcapitalize(buffer);
    }
    send_shoot(buffer);
    get_enemy_shot();
    return (0);
}