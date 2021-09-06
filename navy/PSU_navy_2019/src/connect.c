/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** connect.c
*/

#include "../include/all_includes.h"

int my_str_to_int(char const *str)
{
    int i = 0;
    long nb = 0;

    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        if (nb > 2147483647 || nb < -2147483647)
            return (0);
        i++;
    }
    if (str[i] != 0)
        return (0);
    return ((int) nb);
}

void get_gv(int ac, char **av)
{
    if ((gv = malloc(sizeof(game_variables_t))) == NULL)
        return;;
    gv->win = -1;
    gv->file = my_strdup(av[ac - 1]);
    gv->my_pid = getpid();
    if (ac == 2) {
        my_printf("my pid: %i\n", gv->my_pid);
        gv->status = SERVER;
        gv->enemy_pid = 0;
        gv->server = 1;
    }
    else if (ac == 3 && kill(my_str_to_int(av[ac - 2]), 0) == -1)
        gv->win = 84;
    else {
        my_printf("my pid: %i\n", gv->my_pid);
        gv->status = CLIENT;
        gv->server = 0;
        gv->enemy_pid = my_str_to_int(av[ac - 2]);
        send_signal(CONNECT, gv->my_pid);
        my_printf("%s\n", "successfully connected");
    }
}