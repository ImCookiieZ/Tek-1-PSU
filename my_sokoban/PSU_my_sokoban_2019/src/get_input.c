/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** TODO: add description
*/

#include "../include/my_sokoban.h"

int move_player(int a, int *size)
{
    int valid[8] = {115, 119, 97, 100, 'A', 'B', 'C', 'D'};

    if (a == 27) {
        a = getch();
        if (a == 91)
            a = getch();
    }
    if (a == KEY_RESIZE) {
        check_size(size);
        return (0);
    }
    for (int i = 0; i < 8; i++) {
        if (a == valid[i])
            return (a);
    }
    if (a == -1) {
        endwin();
        exit(1);
    }
    return (0);
}

char get_input(char **map, char *buffer, int *size)
{
    int a;

    noecho();
    a = getch();
    while (1)
        if (a == 32) {
            endwin();
            run_function(buffer, my_strlen(buffer));
            return (0);
        }
        else {
            a = move_player(a, size);
            if (a != 0)
                return (a);
            else
                get_input(map, buffer, size);
        }
}

int my_open(char *file, int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\0';
    int fd = 0;
    int fd_size = 0;
    int ret = 0;

    for (int i = 0; i < size; i++)
        buffer[i] = '\0';
    fd = open(file, O_RDONLY);
    if (fd == -1)
        ret = my_error_print(file);
    else {
        fd_size = read(fd, buffer, size);
        ret = my_error_checker(buffer);
        if (ret == 0)
            run_function(buffer, size);
        free(buffer);
    }
    close(fd);
    return (ret);
}