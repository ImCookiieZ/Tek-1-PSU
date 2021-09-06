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

char **get_ret(char **ret, char **av, int *j_e, flags_t *flags)
{
    DIR *directory;

    for (int i = 1; av[i]; i++) {
        directory = opendir(av[i]);
        if (directory == NULL && av[i][0] != '-') {
            my_printf("my_ls: cannot access '%s", av[i]);
            perror("'");
            exit(84);
            j_e[1]++;
        }
        else if (av[i][0] != '-') {
            ret[j_e[0]] = av[i];
            j_e[0]++;
        }
        else
            my_flag_checker(av[i], flags);
        closedir(directory);
    }
    return (ret);
}

char **open_checker(char **av, flags_t *flags, char **ret)
{
    int *j_and_error = malloc(sizeof(int) * 2);
    int j = 0;
    int my_error = 0;

    j_and_error[0] = 0;
    j_and_error[1] = 0;
    ret = get_ret(ret, av, j_and_error, flags);
    j = j_and_error[0];
    my_error = j_and_error[1];
    ret[j] = NULL;
    if ((ret == NULL || j == 0) && my_error == 0) {
        ret[0] = my_strdup("./");
        ret[1] = NULL;
    }
    return (ret);
}

char **my_checker(char **av, flags_t *flags)
{
    int len = 0;
    char **ret = NULL;
    int j = 1;

    for (int i = 1; av[i]; i++)
        if (av[i][0] != '-')
            len++;
    ret = malloc(sizeof(char *) * (len + 2));
    for (int i = 0; i < len; i++, j++) {
        if (av[i][0] != '-')
            j++;
        ret[i] = malloc(sizeof(char) * my_strlen(av[j]));
        ret[i + 1] = NULL;
    }
    ret = open_checker(av, flags, ret);
    if (ret == NULL) {
        free(ret);
        return (NULL);
    }
    return (ret);
}