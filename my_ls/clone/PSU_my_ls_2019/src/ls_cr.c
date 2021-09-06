/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

int my_printing_cr(char *path, flags_t flags, DIR* directory)
{
    if (directory == NULL) {
        my_printf("my_ls: '%s", path);
        perror("'");
        return (1);
    }
    my_printf("%s:\n", path);
    do_ls(path, flags);
    return (0);
}

void ls_cr(flags_t flags, char *path)
{
    char *file;
    DIR *directory;
    struct stat path_stat;
    struct dirent *dirent_v;
    static int first = 0;

    if (first != 0) my_putchar('\n');
    first++;
    directory = opendir(path);
    if (my_printing_cr(path, flags, directory) == 1)
        return;
    while ((dirent_v = readdir(directory)) != 0) {
        if (dirent_v->d_name[0] == '.') continue;
        file = get_file(dirent_v->d_name, path);
        stat(file, &path_stat);
        if (S_ISDIR(path_stat.st_mode) > 0) ls_cr(flags, file);
    }
    closedir(directory);
}