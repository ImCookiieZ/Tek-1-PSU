/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include <term.h>

#ifndef PSU_TETRIS_2019_TETRIS_H
#define PSU_TETRIS_2019_TETRIS_H

#define RUNNING 42
#define PAUSE 21
#define ERROR 84
#define SUCCESS 0
#define LINE 200
#define COLUMN 400
#define RIGHT 55
#define DOWN 55
#define LEFT 45
#define UP 45
#define LOOSE 2

typedef struct controls_s
{
    char *left;
    char *right;
    char *turn;
    char *drop;
    char *pause;
    char *quit;
} controls;

typedef struct tetrimino_s
{
    char *name;
    int size_x;
    int size_y;
    int color;
    char **array;
    int error;
} tetrimino;

typedef struct game_tetri_s
{
    int pos_x;
    int pos_y;
    tetrimino type;
} game_tetri;

typedef struct game_s
{
    controls ctrl;
    int pause;
    long long highscore;
    long long score;
    long pause_time;
    long start_pause_time;
    tetrimino *tetri;
    game_tetri *cur;
    game_tetri *next;
    int count_tetri;
    int max_rows;
    int max_cols;
    clock_t gametime;
    clock_t starttime;
    int hide_next;
    int debug;
    int level;
} game;

int display_help(char *exec);
char *check_key_input(char *optarg);

controls set_default(void);
void set_controls(int ac, char **av, controls *ctrl, int mode);
void set_game(int ac, char **av, game *info, int mode);
void parse_tetrimino(game *info);

void display_debug(game *info);

void create_game(int ac, char **av, game *info);

char **create_array(int counter);

void my_put_color(char **array);

void display_interface(clock_t gametime, int map_x, int map_y);
void display_header(int max_cols);
int print_extras(game *info);

//game.c
int game_f(game *info);
int change_position(char **ar, game *info, int change_x, int change_y);
int check_loose(game *info, char **ar);
int check_ground(char **ar, game *info);
int check_lines(game *info, char **ar);
int key_event(char **ar, char *input, game *info);
char handle_getch(char input, char prev);
int new_tetri(game *info, char **ar);
int get_turn(game *info, int randi, int randj);
//preparation.c
char **prepare_2d_char_array(int x, int y);
void display_interface(clock_t gametime, int map_x, int map_y);

//error.c
void my_error_exit(char *error_msg);
void my_put_error_str(char *str);
int check_buffer(char *buffer);
int check_tetri(tetrimino *tetri, char *buffer, game *info);

//key_events.c
int key_drop(char **ar, game *info);
int my_key_left(char **ar, game *info);
int my_key_right(char **ar, game *info);
int key_turn(char **ar, game *info);
char **set_char(char **ar, game *info, char c);
int begin_turn(game *info);

//main.c
int get_first_letter(char **ar, int option, int start, int side);

//getopt_array.c
tetrimino null_tetri(char *buffer);
char **short_array(int ac, char **av);
char **long_array(int ac, char **av);

char *my_memset(char *str, int size, char c);
void color_switch(int row, int col, char color);
#endif //PSU_TETRIS_2019_TETRIS_H

/**** DEBUG MODE ***
Key Left : ˆEOD
Key Right : ˆEOC
Key Turn : (space)
Key Drop : x
Key Quit : q
Key Pause : p
Next : Yes
Level : 1
Size : 20*10
Tetriminos : 7
Tetriminos : Name 4 : Error
Tetriminos : Name 5 : Size 1*1 : Color 4 :
*
Tetriminos : Name 6 : Size 2*3 : Color 6 :
*
**
*
Tetriminos : Name 7 : Size 5*4 : Color 3 :
* *
* * *
* *
*
Tetriminos : Name bar : Size 1*4 : Color 2 :
*
*
*
*
Tetriminos : Name inverted-L : Size 2*3 : Color 5 :
*
*
**
Tetriminos : Name square : Size 2*2 : Color 1 :
**
**
Press any key to start Tetris*/