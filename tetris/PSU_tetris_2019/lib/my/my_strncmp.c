/*
** EPITECH PROJECT, 2019
** y
** File description:
** o
*/

#include "include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (my_strlen(s1) < n || my_strlen(s2) < n) {
        if (my_strlen(s1) < my_strlen(s2))
            return (1);
        else
            return (-1);
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] ) {
            if (s1[i] > s2[i])
                return (-1);
            return (1);
        }
    }
    return (0);
}
