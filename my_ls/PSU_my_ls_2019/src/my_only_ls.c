/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

void print_revere(DIR *directory)
{
    struct dirent *dirread_v;

    if ((dirread_v = readdir(directory)) != 0) {
        print_revere(directory);
        if ((dirread_v->d_name[0] != '.')) {
            my_printf("%s\n", dirread_v->d_name);
        }
    }
}

void my_only_ls(flags_t flags, char *path)
{
    DIR *directory;
    struct dirent *dirread_v;

    directory = opendir(path);
    if (directory == NULL)
        return;
    if (flags.r == 1)
        print_revere(directory);
    else
        while ((dirread_v = readdir(directory)) != 0) {
            if ((dirread_v->d_name[0] != '.'))
                my_printf("%s\n", dirread_v->d_name);
        }
    closedir(directory);
}