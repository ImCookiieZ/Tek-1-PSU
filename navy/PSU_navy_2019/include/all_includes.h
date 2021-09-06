/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** all_includes.h
*/

#include "my.h"
#include <signal.h>

#ifndef PSU_NAVY_2019_ALL_INCLUDES_H

#define PSU_NAVY_2019_ALL_INCLUDES_H

#define SERVER 0
#define CLIENT 1
    #define ME 0
    #define YOU 1
    #define CONNECT 19
    #define SHOT 1
    #define HIT 2
    #define MISSED 3
    #define ERROR 84

typedef struct game_vars {
    int server;
    int win;
    int my_pid;
    int enemy_pid;
    int status;
    char *file;
    char **my_map;
    char **enemy_map;
}game_variables_t;

game_variables_t *gv;

char **my_str_to_word_array2(char const *str, char *seperator);
void get_gv(int ac, char **av);
int gameloop();
void prepare_signal(int);
int my_check_signal(int sig);
int my_bin_to_int(int const *bin);
int *my_int_to_bin(int nb);
void my_switch(int function, int message);
int send_user_signal(int signal);
void send_signal(int type, int data);
void send_shoot(char const *coordinates);
void get_enemy_shot();
void receive_shoot(int data);
int check_game_over(char **hidden_enem_array);
int player_turn(void);
void my_switch(int function, int message);
void receive_signal(int sig);
void hit(int data);
void missed(int data);
#endif //PSU_NAVY_2019_ALL_INCLUDES_H
