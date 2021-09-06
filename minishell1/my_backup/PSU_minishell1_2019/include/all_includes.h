/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** add_all_includes
*/

#include "my.h"
#include "struct.h"
#include <zconf.h>
#include <asm/errno.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

typedef struct element_linked_list_env {
    struct element_linked_list_env *before;
    struct element_linked_list_env *next;
    char *str;
    char *var;
    int show;
    int enable;
} list_t;

typedef struct head_list_env {
    struct element_linked_list_env *start;
    struct element_linked_list_env *end;
}heads_t;

int print_terminate(int status);
void sig_handler(int signal);
int my_cd(char *input, heads_t *heads);
int my_if_tree(char *input, heads_t *heads_v, char **env);
int *show_env(heads_t *heads_v);
int my_fork(char *input, heads_t *heads, char **env);
char **my_str_to_word_array2(char const *str, char *seperator);
int count_chars_until_var(char const *input, char c);
int init_env(char **env, heads_t *heads_v);
int my_setenv(heads_t *heads_v, char *str, int first);
char **split_input_set(char *input, int first);
int my_unsetenv(heads_t *heads_v, char *str);