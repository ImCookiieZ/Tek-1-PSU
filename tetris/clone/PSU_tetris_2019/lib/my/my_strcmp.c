/*
** EPITECH PROJECT, 2019
** s
** File description:
** s
*/

#include "include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int len_s1 = my_strlen(s1);
    int ret = 0;

    for (int i = 0; i < len_s1; i++) {
        if ((int) s1[i] != (int) s2[i]) {
            if ((int) s1[i] > (int) s2[i]) {
                return (-1);
            }
            return (1);
        }
        if ((int) s1[i] == 27 || (int) s2[i] == 27)
            i++;
    }
    if (len_s1 < my_strlen(s2))
        return (1);
    return (ret);
}
