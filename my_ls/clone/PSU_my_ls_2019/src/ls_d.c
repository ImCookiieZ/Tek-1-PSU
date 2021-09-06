/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

void my_ls_d(flags_t flags, char *path)
{
    struct stat dir_stat;
    struct passwd *user;
    struct group  *group;

    if (flags.l == 0)
        my_printf("%s\n", path);
    else {
        stat(path, &dir_stat);
        my_print_dash_l(dir_stat);
        user = getpwuid(dir_stat.st_uid);
        group = getgrgid(dir_stat.st_gid);
        my_printf(" %s ", user->pw_name);
        my_printf("%s", group->gr_name);
        my_printf(" %d ", dir_stat.st_size);
        write(1, (ctime(&dir_stat.st_mtime) + 4),  (my_strlen(ctime
        (&dir_stat.st_mtime)) - 13));
        my_printf(" %s\n", path);
    }
}