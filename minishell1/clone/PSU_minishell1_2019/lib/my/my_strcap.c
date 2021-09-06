/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strcap.c
*/

#include "include/my.h"

char *my_strcap(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += 'A' - 'a';
    }
    return (str);
}