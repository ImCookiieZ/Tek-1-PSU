/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** prepare.c
*/

#include "../include/all_includes.h"

int init_env(char **env, heads_t *heads_v)
{
    char *tmp;

    heads_v->start = NULL;
    heads_v->end = NULL;
    for (int i = 0; env[i]; i++) {
        tmp = my_strdup(env[i]);
        if (my_setenv(heads_v, tmp, 1) == 84)
            return (84);
        free(tmp);
    }
    return (0);
}