/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include <errno.h>
#include "../include/all_includes.h"

int find_pos(char *buffer, int row, int col)
{
    int buf_row_start = 0;
    int buf_row_end = 0;
    int buf_col_start = 0;
    int buf_col_end = 0;

    if (!buffer)
        return (0);
    for (int i = 0; i < 25; i += 8) {
        buf_col_start = buffer[i + 2] - 65;
        buf_col_end = buffer[i + 5] - 65;
        buf_row_start = buffer[i + 3] - 49;
        buf_row_end = buffer[i + 6] - 49;
        if (row >= buf_row_start && row <= buf_row_end)
            if (col >= buf_col_start && col <= buf_col_end)
                return (buffer[i]);
    }
    return (0);
}

char **get_array(char *buffer)
{
    char **array = NULL;
    int ship = 0;

    if ((array = malloc(sizeof(char *) * 9)) == NULL)
        return (NULL);
    array[8] = NULL;
    for (int i = 0; i < 8; i += 1) {
        if ((array[i] = malloc(sizeof(char) * 9)) == NULL)
            return (NULL);
        array[i][8] = '\0';
        for (int j = 0; j < 8; j += 1) {
            if ((ship = find_pos(buffer, i, j)) != 0)
                array[i][j] = (char) ship;
            else
                array[i][j] = '.';
        }
    }
    return (array);
}

int start_game(int ac, char **av, char *buffer)
{
    get_gv(ac, av);
    if (gv == NULL || gv->win == 84)
        return (84);
    gv->my_map = get_array(buffer);
    gv->enemy_map = get_array(NULL);
    if (gv->status == SERVER) {
        my_printf("%s\n", "waiting for enemy connection...");
        while (gv->enemy_pid == 0)
            usleep(3000);
        my_printf("\n%s\n", "enemy connected");
    }
    if (gameloop() == 84) {
        if (gv->status == ME) send_signal(ERROR, 1);
        return (84);
    }
    if (gv->server == gv->win) display_game(gv->my_map, gv->enemy_map);
    else my_putchar('\n');
    gv->win ? my_printf("Enemy won\n") : my_printf("I won\n");
    return (0);
}

int main(int ac, char **av)
{
    int fd = 0;
    int len = 0;
    char buffer[32];

    if ((fd = open(av[ac - 1], O_RDONLY)) == -1 || (ac != 3 && ac != 2) ||
        (ac == 3 && (my_str_isnum(av[1]) == 0 || my_getnbr(av[1]) <= 0)))
        return (84);
    len = read(fd, buffer, 100);
    if (len == -1)
        return (84);
    buffer[len] = '\0';
    prepare_signal(SIGUSR1);
    prepare_signal(SIGUSR2);
    if (!check_txt_form(buffer))
        return (start_game(ac, av, buffer));
    return (84);
}