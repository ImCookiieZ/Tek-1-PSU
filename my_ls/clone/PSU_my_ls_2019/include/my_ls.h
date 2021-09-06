/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ls.h
*/

#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#ifndef PSU_MY_LS_2019_PSU_MY_LS_2019_H
typedef struct my_flags {
    int t;
    int r;
    int c_r;
    int l;
    int d;
} flags_t;

void do_ls(char *path, flags_t flags);
void print_stiky_bit(struct stat fileStat);
void print_name(struct dirent *diread_v, struct stat fileStat);
char *get_file(char *name, char *path);
void ls_cr(flags_t flags, char *path);
void my_ls_d(flags_t flags, char *path);
void my_flag_handler(flags_t flags, char *path);
void my_print_dash_l(struct stat fileStat);
void my_ls_l(flags_t flags, char *path);
void my_only_ls(flags_t flags, char *path);
void print_revere(DIR *directory);
char **reverse_folder(char **folder);
void my_flag_checker(char const *av, flags_t *flags);
char **my_checker(char **av, flags_t *flags);
#define PSU_MY_LS_2019_PSU_MY_LS_2019_H

#endif //PSU_MY_LS_2019_PSU_MY_LS_2019_H
