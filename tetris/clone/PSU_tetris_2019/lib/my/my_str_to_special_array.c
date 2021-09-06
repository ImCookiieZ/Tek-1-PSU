/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "include/my.h"

int counts_words_special(char const *str, char c, char d)
{
    int counter = 0;

    for (int i = 0; str[i]; i++) {
        while (str[i] == c || str[i] == d)
            i++;
        counter++;
        while (str[i] != c && str[i] && str[i] != d)
            i++;
    }
    return (counter);
}

int counts_character_special(char const *str, int toto, char c, char d)
{
    int counter = 0;

    for (int i = toto; str[i] != c && str[i] && str[i] != d; i++)
        counter++;
    return (counter);
}

char **my_str_to_special_array(char const *str, char c, char d)
{
    int l = 0;
    int count_words = counts_words_special(str, c, d);
    int string_length = 0;
    char **array = malloc(sizeof(char *) * (count_words + 1));

    for (int i = 0; str[i]; i++) {
        if (str[i] != c && str[i] != d) {
            string_length = counts_character_special(str, i, c, d);
            array[l] = malloc(sizeof(char) * (string_length + 1));
            for (int c = 0; c < string_length; c++) {
                array[l][c] = str[i];
                i++;
            }
            array[l][string_length] = '\0';
            l++;
        }
    }
    array[l] = NULL;
    return (array);
}