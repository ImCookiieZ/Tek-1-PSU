/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_fork.c
*/

#include <sys/wait.h>
#include "../include/all_includes.h"

int my_link_len(heads_t *heads)
{
    int i = 0;
    list_t *element = heads->start;

    while (element) {
        if (element->show)
            i++;
        element = element->next;
    };
    return (i);
}

char **my_get_env(heads_t *head)
{
    char **new_env = NULL;
    int i = 0;

    new_env = malloc(sizeof(char *) * (my_link_len(head) + 1));
    for (list_t *element = head->start; element; element = element->next) {
        if (element->show) {
            new_env[i] = malloc(sizeof(char) * (my_strlen(element->var) +
                my_strlen(element->str) + 2));
            new_env[i] = my_strcpy(new_env[i], element->var);
            new_env[i] = my_strcat(new_env[i], "=");
            new_env[i] = my_strcat(new_env[i], element->str);
            i++;
        }
    }
    new_env[i] = NULL;
    return (new_env);
}

int my_errno_check(char *input)
{
    if (errno == ENOENT)
        return (-1);
    my_printf("%s: %s.", input, strerror(errno));
    if (my_strncmp("gnp.", my_revstr(input), 4) == 0 ||
    my_strncmp("gpj.", my_revstr(input), 4) == 0)
        my_putstr(" Wrong Architecture.");
    else if (errno == ENOEXEC)
        my_putstr(" Binary file not executable.");
    my_putchar('\n');
    return 0;
}

int my_executable(char **possible_path, char *input, char **argv, heads_t *head)
{
    int ret = -1;
    char *my_path = NULL;
    int counetr = 0;
    char **tmp = my_get_env(head);;

    for (int i = 1; possible_path[i] && ret == -1; i++, counetr++) {
        ret = 0;
        my_path = malloc(sizeof(char) * (my_strlen(possible_path[i]) +
            my_strlen(input) + 2));
        my_path = my_strcpy(my_path, possible_path[i]);
        my_path = my_strcat(my_path, "/");
        my_path = my_strcat(my_path, input);
        ret = execve(my_path, argv, tmp);
        ret = my_errno_check(input);
        free(my_path);
    }
    if (ret == -1) {
        ret = execve(input, argv, tmp);
        ret = my_errno_check(input);
    }
    for (int i = 0; tmp[i]; i++) free(tmp[i]);
    free(tmp);
    if (ret == -1) {
        return (0);
    }
    return (-1);
}

int my_fork(char *input, heads_t *heads, char **env)
{
    list_t *element;
    int ret = -1;
    int status = 0;
    char **argv = NULL;
    char **possible_path = NULL;

    for (element = heads->start; element && my_strcmp(element->var, "PATH");
    element = element->next);
    if (element) {
        argv = my_str_to_word_array2(input, " ");
        possible_path = my_str_to_word_array2(element->str, ":");
    }
    if (argv && possible_path) {
        if ((fork()) == 0)
            ret = my_executable(possible_path, argv[0], argv, heads);
    }
    waitpid(0, &status, 0);
    print_terminate(status);
    return (ret);
}