/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

char **reverse_folder(char **folder)
{
    int len = 0;
    char **reverse;
    int i = 0;

    for (; folder[len]; len++);
    i = len - 1;
    reverse = malloc(sizeof(char *) * (len + 1));
    if (reverse == NULL)
        exit(84);
    for (int j = 0; i >= 0; i--, j++) reverse[j] = folder[i];
    reverse[len] = NULL;
    return (reverse);
}
