/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_env.c
*/

#include "../include/all_includes.h"

list_t *env_check(char const *str, heads_t *heads_v)
{
    list_t *element = heads_v->start;

    if (str == NULL)
        return (NULL);
    for (; element && element->var; element = element->next) {
        if (my_strcmp(element->var, str) == 0 && element->show == 1) {
            return (element);
        }
    }
    return (NULL);
}

int my_unsetenv(heads_t *heads_v, char *input)
{
    list_t *element;
    char **var = my_str_to_word_array(input);

    for (int i = 1; var[i]; i++) {
        if ((element = env_check(var[i], heads_v)) == NULL)
            return (84);
        element->show = 0;
    }
    return (0);
}

list_t *get_prepared_element(list_t *new, heads_t *heads_v, char **ar)
{
    if (!(heads_v->start)) {
        heads_v->start = new;
        heads_v->end = new;
    }
    else heads_v->end->next = new;
    new->next = NULL;
    new->str = malloc(sizeof(char ) * (my_strlen(ar[1]) + 1));
    new->str = my_strcpy(new->str, ar[1]);
    new->var = malloc(sizeof(char ) * (my_strlen(ar[0]) + 1));
    new->var = my_strcpy(new->var, ar[0]);
    new->show = 1;
    return (new);
}

int valid_setenv(char **input)
{
    if (my_strcmp(input[0], "setenv") == 0 || my_strcmp(input[0], "unsetenv")
    == 0) {
        my_printf("%s\n", "setenv: Variable name must begin with a letter.");
        return (0);
    }
    if (!((input[0][0] >= 'a' && input[0][0] <= 'z') ||
        (input[0][0] >= 'A' && input[0][0] <= 'Z'))) {
        my_printf("%s\n", "setenv: Variable name must begin with a letter.");
        return (0);
    } else {
        for (int i = 0; input[0][i]; i++)
            if (is_alnum(input[0][i]) != 1) {
                my_printf("%s\n", "setenv: Variable name must "
                "contain alphanumeric characters.");
                return (0);
            }
    }
    return (1);
}

int my_setenv(heads_t *heads_v, char *input, int first)
{
    list_t *new;
    char **ar = split_input_set(input, first);

    if (ar[1] == NULL) {
        show_env(heads_v);
        return (1);
    }
    if (ar[0] == NULL || ar[1] == NULL || my_void_len((void **)ar) != 2)
        return (84);
    if (first == 0 && valid_setenv(ar) == 0) return (0);
    if ((new = env_check(ar[0], heads_v)) == NULL) {
        new = malloc(sizeof(list_t));
        if (new == NULL) return (84);
        new->before = heads_v->end;
        new = get_prepared_element(new, heads_v, ar);
        heads_v->end = new;
    }
    else {
        free(new->str);
        new->str = malloc(sizeof(char ) * (my_strlen(ar[1]) + 1));
        new->str = my_strcpy(new->str, ar[1]);
    }
    return (0);
}