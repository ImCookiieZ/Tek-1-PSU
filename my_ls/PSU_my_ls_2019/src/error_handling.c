/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

void my_flag_checker(char const *av, flags_t *flags)
{
    for (int j = 1; av[j]; j++)
        switch (av[j]) {
            case 'l':
                flags->l = 1;
                break;
            case 'R':
                flags->c_r = 1;
                break;
            case 'd':
                flags->d = 1;
                break;
            case 'r':
                flags->r = 1;
                break;
            case 't':
                flags->t = 1;
                break;
            default:
                exit(84);
        }
}

char **open_checker(char **av, flags_t *flags, char **ret)
{
    int j = 0;
    DIR	*directory;
    char *my_error = ": No such file or directory\n";

    for (int i = 1; av[i]; i++) {
        directory = opendir(av[i]);
        if (directory == NULL && av[i][0] != '-')
            my_printf("my_ls: cannot acces %s%s", av[i], my_error);
        else if (av[i][0] != '-') {
            ret[j] = av[i];
            j++;
        }
        else
            my_flag_checker(av[i], flags);
        closedir(directory);
    }
    ret[j] = NULL;
    return (ret);
}

char **my_checker(char **av, flags_t *flags)
{
    int len = 0;
    char **ret;

    for (int i = 1; av[i]; i++) if (av[i][0] != '-') len += my_strlen(av[i]);
    ret = malloc(sizeof(char *) * (len + 1));
    if (ret == NULL) exit(84);
    ret = open_checker(av, flags, ret);
    if (ret[0] == NULL) {
        free(ret);
        return (NULL);
    }
    return (ret);
}