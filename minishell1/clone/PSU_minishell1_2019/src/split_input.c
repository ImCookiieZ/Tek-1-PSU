/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** split input.c
*/

#include "../include/all_includes.h"

int count_inputs(char const *input)
{
    int counter = 0;
    for (int i = 0; input[i]; i++) {
        if (input[i] == ' ')
            counter++;
    }
    return (counter);
}

int count_chars_until_var(char const *input, char c)
{
    int counter = 0;

    for (; input[counter] && input[counter] != c; counter++);
    return (counter);
}

char *my_str_cpy_at_n(char * dest, char const *src, int begin)
{
    int i = 0;
    int j = 0;

    for (i = begin; src[i]; i++, j++) {
        dest[j] = src[i];
    }
    dest[j] = 0;
    return (dest);
}

char **split_input_set(char *input, int first)
{
    char **ret = malloc(sizeof(char *) * 3);
    char **ar = NULL;
    int count_until_equal = count_chars_until_var(input, '=');
    int len = my_strlen(input);

    if (ret == NULL) exit(84);
    ar = my_str_to_word_array2(input, first ? "=" : " ");
    if (ar[0] == NULL || ar[1] == NULL)
        return (ar);
    ret[1] = malloc(sizeof(char) * (len - count_until_equal + 1));
    if (ret[1] == NULL) exit(84);
    if (first) ret[1] = my_str_cpy_at_n(ret[1], input, count_until_equal + 1);
    else if (ar[2]) ret[1] = my_strdup(ar[2]);
    else ret[2] = NULL;
    ret[0] = my_strdup(ar[first ? 0 : 1]);
    ret[2] = NULL;
    return (ret);
}