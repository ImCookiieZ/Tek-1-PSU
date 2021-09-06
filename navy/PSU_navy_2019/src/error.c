/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int check_input(char *buffer)
{
    if (my_strlen(buffer) != 2)
        return (-1);
    if (buffer[0] > 'H' || buffer[0] < 'A' || buffer[1] < '1' || buffer[1] >
    '8')
        return (-1);
    return (0);
}

int value_twice(char **array, char const buffer[4])
{
    for (int i = 0; array && array[i]; i += 1) {
        for (int j = 0; array[j]; j += 1) {
            if (i != j && !my_strcmp(array[i], array[j]))
                return (-1);
        }
    }
    for (int i = 0; buffer && i < 4; i += 1) {
        for (int j = 0; j < 4; j += 1) {
            if (i != j && buffer[i] == buffer[j])
                return (-1);
        }
    }
    return (0);
}

int get_all_positions(char const *buffer)
{
    char **array = NULL;
    int current = 0;

    if ((array = malloc(sizeof(char *) * 9)) == NULL)
        return (-1);
    array[8] = NULL;
    for (int i = 0; buffer[i + 1] != '\0'; i += 1) {
        if (buffer[i] != ':' && buffer[i] != '\n' && buffer[i + 1] !=
        ':' && buffer[i + 1] != '\n') {
            if ((array[current] = malloc(sizeof(char) * 3)) == NULL)
                return (-1);
            array[current][0] = buffer[i];
            array[current][1] = buffer[i + 1];
            array[current][2] = '\0';
            current += 1;
        }
    }
    return (value_twice(array, NULL));
}

int check_txt_ships(char *buffer)
{
    for (int i = 0; i < 23; i += 8) {
        if (buffer[i + 2] > buffer[i + 5] && buffer[i + 3] > buffer[i + 6])
            return (-1);
        if (buffer[i + 2] != buffer[i + 5] && buffer[i + 3] != buffer[i + 6])
            return (-1);
        if (buffer[i + 5] - buffer[i + 2] > buffer[i] || buffer[i + 6] -
        buffer[i + 3] > buffer[i])
            return (-1);
    }
    return (get_all_positions(buffer));
}

int check_txt_form(char *buffer)
{
    char ships[4] = {buffer[0], buffer[8], buffer[16], buffer[24]};
    char **lines = my_str_to_word_array2(buffer, "\n");
    int i = 0;
    for (i = 0; lines[i]; i++) {
        if (lines[i][1] != ':' || lines[i][4] != ':')
            return (-1);
        if (my_strlen(lines[i]) != 7)
            return (-1);
        if (lines[i][0] - '0' != i + 2)
            return (-1);
        if (lines[i][2] == lines[i][5])
            if (lines[i][0] - '0' != (lines[i][6] - lines[i][3]) + 1)
                return (-1);
        if (lines[i][3] == lines[i][6])
            if (lines[i][0] - '0' != (lines[i][5] - lines[i][2]) + 1)
                return (-1);
    }
    if (i != 4) return(-1);
    if (value_twice(NULL, ships) == -1) return (-1);
    return (check_txt_ships(buffer));
}
