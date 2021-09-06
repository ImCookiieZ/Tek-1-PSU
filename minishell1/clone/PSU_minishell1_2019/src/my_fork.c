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
    if (errno == ENOENT && input[0] != '.')
        return (-1);
    my_errorstr(input);
    my_errorstr(": ");
    my_errorstr(strerror(errno));
    my_errorstr(".");
    if (my_strncmp("gnp.", my_revstr(input), 4) == 0 || \
    my_strncmp("gpj.", my_revstr(input), 4) == 0)
        my_errorstr(" Wrong Architecture.");
    else if (errno == ENOEXEC)
        my_errorstr(" Binary file not executable.");
    my_errorstr("\n");
    return 0;
}

int my_executable(char **paths, char *input, char **argv, heads_t *head)
{
    int ret = 0;
    char *my_path = NULL;
    int counetr = 0;
    char **tmp = my_get_env(head);
    if (input[0] == '.') {
        ret = execve(input, argv, tmp);
        ret = my_errno_check(input);
    }
    else {
        ret = -1;
        for (int i = 1; paths && paths[i] && ret == -1; i++, counetr++) {
            ret = 0;
            my_path = malloc(sizeof(char) * (my_strlen(paths[i]) + \
        my_strlen(input) + 2));
            my_path = my_strcpy(my_path, paths[i]);
            my_path = my_strcat(my_path, "/");
            my_path = my_strcat(my_path, input);
            ret = execve(my_path, argv, tmp);
            ret = my_errno_check(input);
            free(my_path);
        }
    }
    for (int i = 0; tmp[i]; i++) free(tmp[i]);
    free(tmp);
    return (ret == -1 ? 0 : -1);
}

int my_fork(char *input, heads_t *heads, char **env)
{
    list_t *element;
    int ret = -1;
    int status = 0;
    char **argv = NULL;
    char **possible_path = NULL;

    for (element = heads->start; element && (my_strcmp(element->var, "PATH")
    || element->show == 0); element = element->next);
    argv = my_str_to_word_array2(input, " ");
    if (element)
        possible_path = my_str_to_word_array2(element->str, ":");
    if (argv) {
        if ((fork()) == 0)
            ret = my_executable(possible_path, argv[0], argv, heads);
    }
    waitpid(0, &status, 0);
    print_terminate(status);
    return (ret);
}