/*
** EPITECH PROJECT, 2019
** task06
** File description:
** insertionsort
*/

#include "include/my.h"

char **my_sort_str_array(char **array, int size)
{
    char *temp = NULL;

    for (int i = 1; i < size; i++) {
        while (i > 0 && my_strcmp(array[i - 1], array[i]) == -1) {
            temp = my_strdup(array[i - 1]);
            free(array[i - 1]);
            array[i - 1] = my_strdup(array[i]);
            free(array[i]);
            array[i] = my_strdup(temp);
            free(temp);
            i--;
        }
    }
    return (array);
}
