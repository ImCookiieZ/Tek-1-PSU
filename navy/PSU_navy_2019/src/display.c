/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int display_array(char **array)
{
    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; array[i]; i += 1) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j += 1) {
            my_putchar(array[i][j]);
            if (j < 7)
                my_putchar(' ');
            else
                my_putchar('\n');
        }
    }
    my_putchar('\n');
    return (0);
}

int display_game(char **array, char **hidden_enem_array)
{
    my_putstr("\nmy positions:\n");
    display_array(array);
    my_putstr("enemy's positions:\n");
    display_array(hidden_enem_array);
    return (0);
}