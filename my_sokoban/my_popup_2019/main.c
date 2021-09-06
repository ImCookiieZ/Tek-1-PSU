#include <ncurses.h>
#include "include/my.h"

int get_input(int mx, int my, char *string)
{
    char a;

    noecho();
    a = getch();
    if (a == ' ')
        return (0);
    else
        return (get_input(mx, my, string));
}

int main(int argc, char **argv)
{
    int mx = 0;
    int my = 0;
    if (argc != 2)
        return (84);

    noecho();
    initscr();
    getmaxyx(stdscr, mx, my);
    mvprintw(mx / 2, (my - my_strlen(argv[1])) / 2, argv[1]);
    get_input(mx, my, argv[1]);
    refresh();
    endwin();
    return (0);
}