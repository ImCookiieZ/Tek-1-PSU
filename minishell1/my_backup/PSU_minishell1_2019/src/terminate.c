/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** terminate.c
*/

#include "../include/all_includes.h"

int print_terminate(int status)
{
    if (WIFSIGNALED(status))
        my_printf("%s", strsignal(WTERMSIG(status)));
    if (WCOREDUMP(status))
        my_printf(" (core dumped)\n");
    else if (WIFSIGNALED(status))
        my_putchar('\n');
    return (0);
}