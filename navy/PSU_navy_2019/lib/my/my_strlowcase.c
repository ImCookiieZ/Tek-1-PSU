/*
** EPITECH PROJECT, 2019
** o
** File description:
** o
*/

#include "include/my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= 32;
    return (str);
}
