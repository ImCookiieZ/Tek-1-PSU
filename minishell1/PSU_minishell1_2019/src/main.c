/*
** EPITECH PROJECT, 2020
** no
** File description:
** no
*/

#include <signal.h>
#include "../include/all_includes.h"

int show_env(heads_t *heads_v)
{
    for (list_t *element = heads_v->start;
        element != NULL; element = element->next)
        if (element->show == 1)
            my_printf("%s=%s\n", element->var, element->str);
    return (1);
}

void display_shell_name2(heads_t *heads)
{
    list_t *element;
    char **pwd;
    char tmp_path[PATH_MAX];

    for (element = heads->start; element && my_strcmp(element->var, \
        "HOME") != 0; element = element->next);
    if (element && my_strcmp(getcwd(tmp_path, PATH_MAX), element->str) == 0)
        my_printf(" ~]$ ");
    else {
        for (element = heads->start; element && my_strcmp(element->var, \
        "PWD") != 0; element = element->next);
        if (element == NULL) {
            my_printf("]$ ");
            return;
        }
        pwd = my_str_to_word_array(element->str);
        my_putchar(' ');
        my_putstr(pwd[my_void_len((void **) pwd) - 1]);
        my_putstr("]$ ");
    }
}

void display_shell_name(heads_t *heads)
{
    list_t *element = heads->start;

    for (; element && my_strcmp(element->var, "USER") != 0; \
    element = element->next);
    if (element == NULL) {
        my_printf("[%s]$ ", "no@name");
        return;
    }
    my_printf("[%s", element->str);
    for (element = heads->start; element && my_strcmp(element->var, \
        "HOSTNAME") != 0; element = element->next);
    if (element == NULL) {
        my_printf("]$ ");
        return;
    }
    my_putchar('@');
    for (int k = 0; element->str[k] && element->str[k] != '.'; k++)
        my_putchar(element->str[k]);
    display_shell_name2(heads);
}

void sig_handler(int signal)
{
    switch (signal) {
        case SIGFPE:
            my_printf("%s", "Floating-point exception\n");
            break;
        case 2:
            my_printf("");
            break;
        case SIGSEGV:
            my_printf("%s\n", "Segmentation fault (core dumped)");
            break;
        default:
            break;
    }
}

int main(int ac, char **av, char **env)
{
    heads_t *heads_v = malloc(sizeof(heads_t));
    char *input = NULL;
    int valid = 0;
    size_t len = 0;
    int ret = 0;

    if (init_env(env, heads_v) == 84 || ac != 1) return (84);
    while (valid != 2) {
        signal(SIGINT, sig_handler);
        ret = getline(&input, &len, stdin);
        if (ret == -1)
            return (0);
        input[ret - 1] = 0;
        valid = my_if_tree(input, heads_v, env);
        if (valid == 0) {
            my_printf("%s: Command not found.\n", input);
            exit(0);
        }
        signal(SIGINT, sig_handler);
    }
    return (0);
}