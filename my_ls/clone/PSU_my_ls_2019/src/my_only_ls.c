/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

void print_name(struct dirent *diread_v, struct stat fileStat)
{
    char *buffer = malloc(sizeof(char) * 20);
    int size = 0;

    my_printf(" %s", diread_v->d_name);
    if (S_ISLNK(fileStat.st_mode)) {
        size = readlink(diread_v->d_name, buffer, 20);
        buffer[size] = 0;
        my_printf(" -> %s", buffer);
    }
    my_printf("\n");
}

void print_stiky_bit(struct stat fileStat)
{
    my_printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    my_printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    if ((fileStat.st_mode & S_ISGID) && !(fileStat.st_mode & S_IXGRP))
        my_printf("S");
    else if ((fileStat.st_mode & S_ISGID) && (fileStat.st_mode & S_IXGRP))
        my_printf("s");
    else
        my_printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    my_printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    my_printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
}

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
    else {
        while ((dirread_v = readdir(directory)) != 0) {
            if ((dirread_v->d_name[0] != '.'))
                my_printf("%s\n", dirread_v->d_name);
        }
    }
    closedir(directory);
}