/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

void debug_bools(game *info)
{
    if (info->hide_next)
        my_putstr("Next : No\n");
    else
        my_putstr("Next : Yes\n");
}

void debug_key(char const *buffer, char *input)
{
    my_printf("%s ", buffer);
    for (int i = 0; input[i]; i++) {
        if (input[i] == 27)
            my_printf("%s", "^E");
        else
            my_printf("%c", input[i]);
    }
    my_printf("\n");
}

void display_tetri(game *info)
{
    my_printf("Tetriminos : %d\n", info->count_tetri);
    for (int i = 0; i < info->count_tetri; i += 1) {
        if (!info->tetri[i].error) {
            my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n",
                info->tetri[i].name, info->tetri[i].size_x, info->tetri[i]
                .size_y, info->tetri[i].color);
            for (int j = 0; info->tetri[i].array[j] != NULL; j += 1)
                my_printf("%s\n", info->tetri[i].array[j]);
        } else
            my_printf("Tetriminos : Name %s : Error\n", info->tetri[i].name);
    }
}

void display_debug(game *info)
{
    char ch = 0;
    my_putstr("*** DEBUG MODE ***\n");
    debug_key("Key Left :", info->ctrl.left);
    debug_key("Key Right :", info->ctrl.right);
    debug_key("Key Turn :", info->ctrl.turn);
    debug_key("Key Drop :", info->ctrl.drop);
    debug_key("Key Quit :", info->ctrl.quit);
    debug_key("Key Pause :", info->ctrl.pause);
    debug_bools(info);
    my_printf("Level : %d\n", info->level);
    my_printf("Size : %d*%d\n", info->max_rows, info->max_cols);
    display_tetri(info);
    my_printf("Press any key to start Tetris\n");
    scanf("%c", &ch);
}