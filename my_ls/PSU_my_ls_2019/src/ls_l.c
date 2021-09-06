/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

long get_total_size(char *path)
{
    DIR *directory = opendir(path);
    struct dirent *dirent_v;
    struct stat dir_stat;
    char *tmp;
    long size = 0;

    while ((dirent_v = readdir(directory))) {
        tmp = malloc(sizeof(char) * (my_strlen(dirent_v->d_name) + my_strlen
            (path) + 1));
        if (tmp == NULL)
            exit(84);
        tmp = my_strcpy(tmp, path);
        tmp = my_strcat(tmp, dirent_v->d_name);
        if ((lstat(tmp, &dir_stat)) == 0)
            (dirent_v->d_name[0] != '.') ? size += dir_stat.st_blocks / 2 : 0;
        free(tmp);
    }
    return (size);
}

void reverse_l(DIR *directory, char *path)
{
    struct dirent *dirread_v;
    struct stat fileStat;
    struct passwd *user;
    struct group  *group;

    if ((dirread_v = readdir(directory)) != 0) {
        reverse_l(directory, path);
        if ((dirread_v->d_name[0] != '.')) {
            stat(get_file(dirread_v->d_name, path), &fileStat);
            user = getpwuid(fileStat.st_uid);
            group = getgrgid(fileStat.st_gid);
            my_print_dash_l(fileStat);
            my_printf(" %s ", user->pw_name);
            my_printf("%s", group->gr_name);
            my_printf(" %d ", fileStat.st_size);
            write(1, (ctime(&fileStat.st_mtime) + 4), \
            (my_strlen(ctime(&fileStat.st_mtime)) - 13));
            my_printf(" %s\n", dirread_v->d_name);
        }
    }
}

void ls_printing_l(DIR *directory, char *path)
{
    struct dirent *dirread_v;
    struct stat file_stat;
    struct passwd *user;
    struct group  *group;

    while ((dirread_v = readdir(directory)) != 0) {
        if ((dirread_v->d_name[0] != '.')) {
            stat(get_file(dirread_v->d_name, path), &file_stat);
            user = getpwuid(file_stat.st_uid);
            group = getgrgid(file_stat.st_gid);
            my_print_dash_l(file_stat);
            my_printf(" %s ", user->pw_name);
            my_printf("%s", group->gr_name);
            my_printf(" %d ", file_stat.st_size);
            write(1, (ctime(&file_stat.st_mtime) + 4),  (my_strlen(ctime
            (&file_stat.st_mtime)) - 13));
            my_printf(" %s\n", dirread_v->d_name);
        }
    }
}

void my_ls_l(flags_t flags, char *path)
{
    DIR *directory;

    directory = opendir(path);
    if (directory != NULL) my_printf("total %u\n", get_total_size(path));
    if (directory == NULL) return;
    if (flags.r == 1) reverse_l(directory, path);
    else ls_printing_l(directory, path);

}

void my_print_dash_l(struct stat fileStat)
{
    my_printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    my_printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    my_printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    my_printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    my_printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    my_printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    my_printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    my_printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    my_printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    if (fileStat.st_mode & S_ISVTX)
        my_printf("T.");
    else if (fileStat.st_mode & S_IXOTH)
        my_printf("x.");
    else
        my_printf("-.");
    my_printf(" %d", fileStat.st_nlink);
}