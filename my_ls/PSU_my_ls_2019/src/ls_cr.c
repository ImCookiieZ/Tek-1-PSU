/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

void ls_cr(flags_t flags, char *path)
{
    char *file;
    DIR *directory;
    struct stat path_stat;
    struct dirent *dirent_v;
    static int first = 0;

    if (first != 0) my_putchar('\n');
    first++;
    my_printf("%s:\n", path);
    if (flags.d) my_ls_d(flags, path);
    else if (!(flags.l)) my_only_ls(flags, path);
    else
        if (flags.l) my_ls_l(flags, path);
    directory = opendir(path);
    while ((dirent_v = readdir(directory)) != 0) {
        if (dirent_v->d_name[0] == '.') continue;
        file = get_file(dirent_v->d_name, path);
        stat(file, &path_stat);
        if (S_ISDIR(path_stat.st_mode) > 0) ls_cr(flags, file);
    }
    closedir(directory);
}