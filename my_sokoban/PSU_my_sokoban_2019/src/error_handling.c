/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** TODO: add description
*/

#include "../include/my_sokoban.h"

int my_error_checker(char *buffer)
{
    int len = my_strlen(buffer);

    for (int i = 0; i < len; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '#' &&
            buffer[i] != 'O' && buffer[i] != 'P' && buffer[i] != 'X') {
            write(2, "Error: invalid map!\n", 20);
            exit(84);
        }
    }
    return (0);

}

int my_error_print(char *av)
{
    int len = my_strlen(av);

    write(2, "Error: ", 6);
    write(2, av, len);
    if (errno == EACCES)
        write(2, ": Argument list too long\n", 26);
    if (errno == EINTR)
        write(2, ": Interrupted function call\n", 29);
    if (errno == EISDIR)
        write(2, ": Is a directory\n", 18);
    if (errno == ENOENT)
        write(2, ": No such file or directory\n", 29);
    return (84);
}