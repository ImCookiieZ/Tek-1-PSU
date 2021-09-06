/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** if_trees.c
*/

#include "../include/all_includes.h"

int issign(char c)
{
    if (c == '-' || c == '+')
        return (1);
    return (0);
}

int isnum(char c)
{
    if ((c <= '9' && c >= '0'))
        return (1);
    return (0);
}

int error_exit(char *input)
{
    int i = 0;
    int j = 0;
    if (input && my_str_isnum(input) != 1) {
        for (; input[i] && issign(input[i]); i++);
        for (j = i; input[j] && isnum(input[j]); j++);
        if (j != 0 && isnum(input[j - 1]) && my_str_isnum(input) == 0)
            write(1, "exit: Badly formed number.\n", 27);
        else write(1, "exit: Expression Syntax.\n", 25);
        return (1);
    }
    return (0);
}

int my_if_tree2(char **ar, heads_t *heads_v, char **env, char *input)
{
    if (my_strcmp(ar[0], "exit") == 0) {
        if (error_exit(ar[1]) == 1)
            return (1);
        else {
            my_printf("exit\n");
            exit(ar[1] ? my_getnbr(ar[1]) : 0);
        }
    }
    if (my_strcmp(ar[0], "cd") == 0) {
        my_cd(input, heads_v);
        return (1);
    }
    if (my_fork(input, heads_v, env) != 0)
        return (1);
    return (0);
}

int my_if_tree(char *input, heads_t *heads_v, char **env)
{
    char **ar = my_str_to_word_array2(input, " ");

    if (my_strcmp(ar[0], "setenv") == 0) {
        my_setenv(heads_v, input, 0);
        return (1);
    }
    if (my_strcmp(ar[0], "unsetenv") == 0) {
        my_unsetenv(heads_v, input);
        return (1);
    }
    if (my_strcmp(ar[0], "env") == 0 && my_strcmp(ar[1], "-i") != 0) {
        show_env(heads_v);
        return (1);
    }
    if (my_strcmp(ar[0], "env") == 0 && my_strcmp(ar[1], "-i") == 0) {
        for (list_t *el = heads_v->start; el; el = el->next)
            el->show = 0;
        return (1);
    }
    return (my_if_tree2(ar, heads_v, env, input));
}