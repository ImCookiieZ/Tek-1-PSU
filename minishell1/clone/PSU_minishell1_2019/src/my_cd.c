/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd.c
*/

#include <dirent.h>
#include "../include/all_includes.h"

int my_change_to_previus(heads_t *heads)
{
    list_t *prev = heads->start;
    list_t *now = heads->start;
    char *tmp = NULL;

    for (; prev && (my_strcmp(prev->var, "OLDPWD") != 0 || \
    prev->show == 0 || prev->enable == 0); prev = prev->next);
    for (; now && (my_strcmp(now->var, "PWD") != 0 || \
    now->show == 0); now = now->next);
    if (prev) tmp = prev->str;
    if (now && prev) prev->str = now->str;
    if (now && tmp) now->str = tmp;
    if (now)
        return (chdir(now->str));
    return (-1);
}

int my_cd_add(char **ar, heads_t *heads, list_t *el)
{
    int ret = 0;
    char new_path[PATH_MAX];

    if (!(ar[1]) || my_strcmp(ar[1], "~") == 0) {
        for (el = heads->start; el && (my_strcmp(el->var, "HOME") != 0 || \
        el->show == 0); el = el->next);
        if (el) ret = chdir(el->str);
        getcwd(new_path, PATH_MAX);
    }
    else if (el && my_strcmp(ar[1], "-") == 0)
        ret = my_change_to_previus(heads);
    else
        ret = chdir(ar[1]);
    if (ret == -1)
        if (ar[1]) {
            my_errorstr(ar[1]);
            my_errorstr(": ");
            my_errorstr(strerror(errno));
            my_errorstr(".\n");
        }
    return (ret);
}

int my_cd(char *input, heads_t *heads)
{
    char **ar = my_str_to_word_array2(input, " ");
    char my_cwd[PATH_MAX];
    list_t *el = heads->start;

    getcwd(my_cwd, PATH_MAX);
    if (my_cd_add(ar, heads, el) == 0) {
        for (el = heads->start; el && (my_strcmp(el->var, "OLDPWD") != 0 || \
        el->show == 0); el = el->next);
        if (el) el->enable = 1;
        if (el) free(el->str);
        if (el) el->str = my_strdup(my_cwd);
    }
    getcwd(my_cwd, PATH_MAX);
    for (el = heads->start; el && (my_strcmp(el->var, "PWD") != 0 || \
    el->show == 0); el = el->next);
    if (el) {
        free(el->str);
        el->str = my_strdup(my_cwd);
    }
    return (0);
}