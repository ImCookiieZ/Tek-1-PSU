/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** signal_handling.c
*/

#include "../include/all_includes.h"

void send_signal(int type, int data)
{
    int *type_bin = my_int_to_bin(type);
    int *type_data = my_int_to_bin(data);

    usleep(10000);
    for (int i = 0; i < 16; i++) {
        if (type_bin[i] == 0)
            send_user_signal(SIGUSR1);
        else if (type_bin[i] == 1)
            send_user_signal(SIGUSR2);
    }
    usleep(10000);
    for (int i = 0; i < 16; i++) {
        if (type_data[i] == 0)
            send_user_signal(SIGUSR1);
        else if (type_data[i] == 1)
            send_user_signal(SIGUSR2);
    }
}

int send_user_signal(int signal)
{
    if (kill(gv->enemy_pid, signal) == -1) {
        my_printf("sth went wrong\n");
        return (0);
    }
    usleep(10000);
    return (1);
}

void receive_signal(int sig)
{
    static int *msg_type = NULL;
    static int *msg_data = NULL;
    static int pos = 0;

    if (msg_type == NULL || msg_data == NULL) {
        msg_type = malloc(sizeof(int) * 16);
        msg_data = malloc(sizeof(int) * 16);
        if (msg_data == NULL || msg_type == NULL) return;
    }
    if (pos < 16)
        msg_type[pos] = my_check_signal(sig);
    else
        msg_data[pos - 16] = my_check_signal(sig);
    pos++;
    if (pos == 32)
        my_switch(my_bin_to_int(msg_type), my_bin_to_int(msg_data));
    if (pos >= 32) {
        msg_type = NULL;
        msg_data = NULL;
        pos = 0;
    }
}

int *my_int_to_bin(int nb)
{
    int digits[16];
    int tmp = 1;
    int *ret = malloc(sizeof(int) * 16);

    for (int i = 1; i < 17; i++) {
        digits[16 - i] = (int)tmp;
        tmp *= 2;
    }
    if (ret == NULL)
        return (NULL);
    for (int i = 0; i < 16; i++)
        if (digits[i] <= nb) {
            nb -= digits[i];
            ret[i] = 1;
        }
        else
            ret[i] = 0;
    return (ret);
}

int my_bin_to_int(int const *bin)
{
    int tmp = 1;
    int digits[16];
    int ret = 0;

    for (int i = 1; i < 17; i++) {
        digits[16 - i] = (int)tmp;
        tmp *= 2;
    }
    for (int i = 0; i < 16; i++)
        if (bin[i] == 1)
            ret += digits[i];
    return (ret);
}