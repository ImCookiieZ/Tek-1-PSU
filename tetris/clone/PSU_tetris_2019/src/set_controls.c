/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

const char *flags = ":hL:l:r:t:d:q:p:wDs:";

const struct option long_options[] =
{
    {"help", 0, 0, 'h'},
    {"level", 1, 0, 'L'},
    {"key-left", 1, 0, 'l'},
    {"key-right", 1, 0, 'r'},
    {"key-turn", 1, 0, 't'},
    {"key-drop", 1, 0, 'd'},
    {"key-quit", 1, 0, 'q'},
    {"key-pause", 1, 0, 'p'},
    {"map-size", 1, 0, 'm'},
    {"without-next", 0, 0, 'w'},
    {"debug", 0, 0, 'D'},
    {0, 0, 0, 0}
};

controls set_default(void)
{
    controls ctrl;
    ctrl.right = my_strdup(tigetstr("kcuf1"));
    ctrl.left = my_strdup(tigetstr("kcub1"));
    ctrl.turn = my_strdup(tigetstr("kcuu1"));
    ctrl.drop = my_strdup(tigetstr("kcud1"));
    ctrl.quit = my_strdup("q");
    ctrl.pause = my_strdup(" ");
    return (ctrl);
}

int get_opt(int ac, char **av, int mode)
{
    int opt = 0;
    int opt_i = 0;

    if (!mode)
        opt = getopt(ac, av, flags);
    else
        opt = getopt_long(ac, av, flags, long_options, &opt_i);
    return (opt);
}

void set_controls(int ac, char **av, controls *ctrl, int mode)
{
    int opt = 0;
    char **array = NULL;
    if (!mode) array = short_array(ac, av);
    else array = long_array(ac, av);
    while ((opt = get_opt(my_arraylen(array), array, mode)) != -1) {
        if (opt == 'h') display_help(av[0]);
        if (opt == 'l') ctrl->left = check_key_input(optarg);
        if (opt == 'r') ctrl->right = check_key_input(optarg);
        if (opt == 't') ctrl->turn = check_key_input(optarg);
        if (opt == 'd') ctrl->drop = check_key_input(optarg);
        if (opt == 'p') ctrl->pause = check_key_input(optarg);
        if (opt == 'q') ctrl->quit = check_key_input(optarg);
        if (opt == ':') my_error_exit("Invalid argument for option\n");
        if (opt == '?') my_error_exit("Invalid option\n");
    }
    for (int i = 0; array[i]; free(array[i]), i += 1);
    free(array);
    optind = 0;
}

void set_size(game *info, char *arg)
{
    int j = 0;
    char *tmp = NULL;
    int counter = 0;
    for (int i = 0; arg[i]; i += 1) {
        if (arg[i] != ',' && (arg[i] < '0' || arg[i] > '9'))
            my_error_exit("Invalid argument for option\n");
        if (arg[i] == ',')
            counter += 1;
    }
    if (counter != 1) my_error_exit("Invalid argument for option\n");
    if ((tmp = malloc(sizeof(char) * 4)) == NULL) exit(84);
    for (int i = 0; i < 4; tmp[i] = '\0', i += 1);
    for (; arg[j] && arg[j] != ','; tmp[j] = arg[j], j += 1);
    info->max_rows = my_getnbr(tmp);
    for (int i = 0; i < 4; tmp[i] = '\0', i += 1);
    for (int k = 0; arg[j]; tmp[k] = arg[j], k += 1, j += 1);
    info->max_cols = my_getnbr(tmp);
    free(tmp);
}

void set_game(int ac, char **av, game *info, int mode)
{
    int opt = 0;
    char **array = NULL;
    if (!mode) array = short_array(ac, av);
    else array = long_array(ac, av);
    while ((opt = get_opt(my_arraylen(array), array, mode)) != -1) {
        if (opt == 'D')
            info->debug = 1;
        if (opt == 'w')
            info->hide_next = 1;
        if (opt == 'L')
            info->level = my_getnbr(optarg);
        if (opt == 'm')
            set_size(info, optarg);
    }
    for (int i = 0; array[i]; free(array[i]), i += 1);
    free(array);
    optind = 0;
}
