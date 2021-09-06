/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int display_help(char *exec)
{
    char buffer[1000];
    int fd = 0;
    int size = 0;

    if ((fd = open("help", O_RDONLY)) == -1)
        exit(84);
    if ((size = read(fd, buffer, 1000)) == -1)
        exit(84);
    buffer[size] = '\0';
    my_printf("Usage: %s [options]\n", exec);
    write(1, buffer, size);
    exit(0);
}

char *check_key_input(char *arg)
{
    char *ret = malloc(sizeof(char) * 4096);

    if (ret == NULL)
        my_error_exit("malloc failed\n");
    if (arg == NULL || arg[0] == '\0')
        my_error_exit("Invalid argument for option\n");
    if (my_strlen(arg) > 1 && arg[0] != 27)
        my_error_exit("Invalid argument for option\n");
    for (int i = 0; arg[i]; i++) {
        if (arg[i] < 32)
            my_error_exit("Invalid argument for option\n");
    }
    ret = my_strdup(arg);
    return (ret);
}

void create_game(int ac, char **av, game *info)
{
    int i;
    if ((setupterm(NULL, 0, &i)) < 0) my_error_exit("wrong term");
    info->ctrl = set_default();
    set_controls(ac, av, &info->ctrl, 0);
    set_controls(ac, av, &info->ctrl, 1);
    info->max_cols = 10;
    info->my_lines = 0;
    info->pause = FALSE;
    info->start_pause_time = 0;
    info->pause_time = 0;
    info->highscore = 0;
    info->score = 0;
    info->cur = NULL;
    info->next = NULL;
    info->max_rows = 20;
    info->hide_next = 0;
    info->debug = 0;
    info->level = 1;
    set_game(ac, av, info, 0);
    set_game(ac, av, info, 1);
    parse_tetrimino(info);
}