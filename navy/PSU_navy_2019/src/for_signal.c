/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int my_check_signal(int sig)
{
    if (sig == SIGUSR1)
        return (0);
    else if (sig == SIGUSR2)
        return (1);
    else
        return (-1);
}

void prepare_signal(int signal_id)
{
    struct sigaction action;

    action.sa_flags = SA_SIGINFO;
    action.sa_handler = receive_signal;
    sigemptyset (&action.sa_mask);
    if (sigaction (signal_id, &action, NULL) == -1)
        return;
}