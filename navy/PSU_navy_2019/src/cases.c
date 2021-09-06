/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int my_second_switch(int function, int message)
{
    if (function == HIT) {
        hit(message);
        usleep(10000);
        return (1);
    }
    else if (function == MISSED) {
        missed(message);
        usleep(10000);
        return (1);
    } else {
        if (function == ERROR) {
            gv->win = 84;
            usleep(10000);
            return (1);
        }
    }
    return (0);
}

void my_switch(int function, int message)
{
    if (function == CONNECT) {
        gv->enemy_pid = message;
        usleep(10000);
        return;
    }
    else if (function == SHOT) {
        receive_shoot(message);
        usleep(10000);
        return;
    } else {
        if (!my_second_switch(function, message))
            my_printf("received unusual signal: %i do sth: %i\n", function,
                message);
    }
}