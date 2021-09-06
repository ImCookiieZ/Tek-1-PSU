/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

void my_put_color(char **array)
{
    for (int i = 0; array[i]; i += 1)
        for (int j = 0; array[i][j]; j += 1)
            color_switch(i + 7, j * 2 + 31, array[i][j]);
}

int get_first_letter(char **ar, int option, int start, int side)
{
    int counter = 0;

    if (option == LINE) {
        if (side == LEFT)
            for (int i = 0; ar[start][i] && ar[start][i] == ' '; i++)
                counter++;
        else
            for (int i = my_strlen(ar[start]) - 1; i >= 0 &&
                (ar[start][i] == ' ' || ar[start][i] == 0); i--)
                counter++;
    }
    if (option == COLUMN) {
        if (side == DOWN)
            for (int i = my_arraylen(ar) - 1; i >= 0 && (ar[i][start] == ' '
            || ar[i][start] == 0);
            i--)
                counter++;
        else
            for (int i = 0; ar[i] && ar[i][start] == ' '; i++, counter++);
    }
    return (counter);
}

int main(int ac, char **av)
{
    game info;
    time_t t;
    srand(time(&t));
    info.count_tetri = count_tetri();
    create_game(ac, av, &info);
    if (info.debug)
        display_debug(&info);
    info.starttime = clock();
    del_curterm(cur_term);
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    check_resize(&info);
    curs_set(0);
    start_color();
    game_f(&info);
    endwin();
    return (0);
}