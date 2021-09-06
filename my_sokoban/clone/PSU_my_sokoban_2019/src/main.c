/*
** EPITECH PROJECT, 2019
** main
** File description:
** bsq
*/

#include "../include/my_sokoban.h"

void my_display_usage(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map  file");
    my_putstr(" representing the warehouse map, containing ‘#’ for walls,");
    my_putstr("\n          'P' for the player, ‘X’ for boxes and ‘O’ for ");
    my_putstr("storage locations.\n");
}

int main(int ac, char **av)
{
    char *fd;
    struct stat buf;
    char *buffer;
    int ret = 0;

    if (ac != 2) {
        write(2, "Error: wrong number of arguments\n", 33);
        return (84);
    }
    else if (my_strcmp(av[1], "-h") == 0) {
        my_display_usage();
        return (0);
    }
    fd = av[1];
    stat(fd, &buf);
    ret = my_open(av[1], buf.st_size);
    return (ret);
}