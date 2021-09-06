/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

char **create_array(int counter)
{
    DIR *dir;
    struct dirent *current;
    char **array = NULL;

    if ((array = malloc(sizeof(char *) * (counter + 1))) == NULL)
        exit (84);
    array[counter] = NULL;
    if ((dir = opendir("tetriminos")) == NULL)
        exit(84);
    for (int i = 0; (current = readdir(dir)); i += 1) {
        if (my_strlen(current->d_name) > 2 && my_strcmp(".tetrimino",
            current->d_name)) {
            array[i] = my_strdup(current->d_name);
        } else
            i -= 1;
    }
    closedir(dir);
    return (array);
}