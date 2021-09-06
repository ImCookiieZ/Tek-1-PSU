/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

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
    create_game(ac, av, &info);
    if (info.debug)
        display_debug(&info);
    info.starttime = clock();
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);
    start_color();
    game_f(&info);
    endwin();
    return (0);
}