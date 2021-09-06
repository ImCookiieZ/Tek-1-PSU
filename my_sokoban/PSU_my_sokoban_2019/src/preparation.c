/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** TODO: add description
*/

#include "../include/my_sokoban.h"

int *my_get_minsize(char *buffer, int len)
{
    int lines = 0;
    int max_column = 0;
    int column = 0;
    int *ar = malloc(sizeof(int) * 2);

    for (int i = 0; i < len; i++) {
        column++;
        if (buffer[i] == '\n') {
            lines++;
            if (column > max_column)
                max_column = column;
            column = 0;
        }
    }
    ar[0] = max_column;
    ar[1] = lines;
    return (ar);
}

int check_size(int const *ar)
{
    int mx = 0;
    int my = 0;
    char *string = "Increase your terminal!\n";
    int c;
    int i = 0;

    clear();
    getmaxyx(stdscr, mx, my);
    while (mx < ar[1] || my < ar[0]) {
        mvprintw(mx / 2, (my - my_strlen(string)) / 2, "%s", string);
        getmaxyx(stdscr, mx, my);
        refresh();
        c = getch();
        if (c == KEY_RESIZE && (mx < ar[1] || my < ar[0]))
            clear();
        i++;
    }
    clear();
    return (0);
}

char **get_map(char const *buffer, int lines, int len)
{
    int tmp_i = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int column = 0;
    char **map = malloc(sizeof(char *) * (lines + 1));

    for (i = 0; j < lines; j++, i++) {
        tmp_i = i;
        for (column = 0; buffer[tmp_i] != '\n' && buffer[tmp_i] != '\0';
        tmp_i++)
            column++;
        map[j] = malloc(sizeof(char) * (column + 2));
        for (k = 0; buffer[i] != '\n'; k++, i++)
            map[j][k] = buffer[i];
        map[j][k] = '\n';
        map[j][k + 1] = '\0';
    }
    map[j] = NULL;
    return (map);
}

int **get_coordinates(char **map)
{
    int counter = 0;
    int **coordinates = NULL;
    int k = 0;

    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == 'O')
                counter++;
    coordinates = malloc(sizeof(int *) * (counter + 1));
    coordinates[counter] = NULL;
    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == 'O') {
                coordinates[k] = malloc(sizeof(int) * 2);
                coordinates[k][0] = i;
                coordinates[k][1] = j;
                k++;
            }
    return (coordinates);

}

void run_function(char *buffer, int len)
{
    int *ar = my_get_minsize(buffer, len);
    int mx = 0;
    int my = 0;
    char **map = get_map(buffer, ar[1], len);
    int **o_s = get_coordinates(map);

    getmaxyx(stdscr, mx, my);
    initscr();
    check_size(ar);
    game_print(map, o_s);
    game(map, o_s, buffer, ar);
    for (int i = 0; i < ar[1]; i++)
        free(map[i]);
    for (int i = 0; o_s[i]; i++)
        free(o_s);
    free(o_s);
    free(map);
    endwin();
    free(ar);
}