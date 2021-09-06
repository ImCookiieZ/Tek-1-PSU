/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

tetrimino null_tetri(char *bf)
{
    tetrimino new;
    new.name = NULL;
    new.color = 0;
    new.size_x = 0;
    new.size_y = 0;
    new.array = NULL;
    new.error = check_buffer(bf);
    return (new);
}

char **long_array(int ac, char **av)
{
    char **new = NULL;
    int len = 1;
    int j = 1;
    for (int i = 0; i < ac; i += 1) {
        if (my_strlen(av[i]) > 2 && av[i][0] == '-' && av[i][1] == '-')
            len += 1;
    }
    if ((new = malloc(sizeof(char *) * (len + 1))) == NULL) exit (84);
    new[len] = NULL;
    new[0] = my_strdup(av[0]);
    for (int i = 1; i < ac; i += 1) {
        if (my_strlen(av[i]) > 2 && av[i][0] == '-' && av[i][1] == '-') {
            new[j] = my_strdup(av[i]);
            j += 1;
        }
    }
    return (new);
}

void check_short_array(char **array)
{
    int count_flag = 0;
    int count_arg = -1;
    for (int i = 0; array[i]; i += 1)
        if (array[i][0] == '-')
            count_flag += 1;
    for (int i = 0; array[i]; i += 1)
        if (array[i][0] != '-')
            count_arg += 1;
    if (count_arg > count_flag)
        my_error_exit("Invalid argument for option\n");
}

char **short_array(int ac, char **av)
{
    char **new = NULL;
    int len = 0;
    int j = 0;

    for (int i = 0; i < ac; i += 1) {
        if ((my_strlen(av[i]) > 1 && (av[i][0] == '-' && av[i][1] != '-')) ||
        av[i][0] != '-')
            len += 1;
    }
    if ((new = malloc(sizeof(char *) * (len + 1))) == NULL) exit (84);
    new[len] = NULL;
    for (int i = 0; i < ac; i += 1) {
        if ((my_strlen(av[i]) > 1 && (av[i][0] == '-' && av[i][1] != '-')) ||
        av[i][0] != '-') {
            new[j] = my_strdup(av[i]);
            j += 1;
        }
    }
    check_short_array(new);
    return (new);
}