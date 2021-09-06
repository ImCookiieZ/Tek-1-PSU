/*
** EPITECH PROJECT, 2019
** y
** File description:
** o
*/

#include "include/my.h"

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] <= 'z' && str[i] >= 'a')
            str[i] -= ('a' - 'A');
    return (str);
}