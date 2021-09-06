/*
** EPITECH PROJECT, 2019
** o
** File description:
** o
*/

#include "include/my.h"

char *my_strlowcase(char *str)
{
    char *tmp = my_strdup(str);

    for (int i = 0; tmp[i]; i += 1)
        if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            tmp[i] -= 32;
    return (tmp);
}
