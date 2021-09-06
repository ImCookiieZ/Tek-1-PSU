/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

void do_ls(char *path, flags_t flags)
{
    if (flags.d)
        my_ls_d(flags, path);
    if (!(flags.l) && flags.d == 0)
        my_only_ls(flags, path);
    if (flags.l && flags.d == 0)
        my_ls_l(flags, path);
}

char *get_file(char *name, char *path)
{
    int len_name = my_strlen(name);
    int len_path = my_strlen(path);
    char *file = malloc(sizeof(char) * (len_name + len_path + 2));

    if (file == NULL)
        exit(84);
    file = my_strcpy(file, path);
    if (file[len_path - 1] != '/') {
        file[len_path] = '/';
        file[len_path + 1] = '\0';
    }
    file = my_strcat(file, name);
    return (file);
}

void my_flag_handler(flags_t flags, char *path)
{
    if (flags.c_r) {
        ls_cr(flags, path);
        return;
    }
    if (flags.d) {
        my_ls_d(flags, path);
        return;
    }
    if (!(flags.l)) {
        my_only_ls(flags, path);
        return;
    }
    if (flags.l) {
        my_ls_l(flags, path);
        return;
    }
}

void my_ls(flags_t flags, char **folder)
{
    int first = 0;
    int i = 0;
    int len = 0;

    for (; folder[len]; len++);
    if (len == 1) {
        my_flag_handler(flags, folder[0]);
        return;
    }
    if (flags.r == 1)
        folder = reverse_folder(folder);
    for (; folder[i]; i++) {
        if (first != 0 && flags.d == 0) my_printf("\n");
        if (flags.d != 1) my_printf("%s:\n", folder[i]);
        my_flag_handler(flags, folder[i]);
        first++;
    }
}

int main(int argc, char **argv)
{
    flags_t flags = {0, 0, 0, 0, 0};
    char **folder = my_checker(argv, &flags);

    if (argc == 1)
        my_only_ls(flags, "./");
    else if (argc == 2 && my_strcmp(argv[1], "--help") == 0) {
        my_printf("Usage: my_ls -[OPTION]... [FILE]...\n");
        my_printf("Options are : \n");
        my_printf("\tl : Long listing format\n");
        my_printf("\tr : reverse order\n");
        my_printf("\td : list directories themselves, not their contents\n");
        my_printf("\tR : list subdirectories recursively\n");
        my_printf("\tt : sort by modification time, newest first\n");
    }
    else
        my_ls(flags, folder);
    free(folder);
    return (0);
}