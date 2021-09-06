/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/my.h"

int count_tetri(void)
{
    DIR *dir;
    int counter = 0;
    struct dirent *current;

    if ((dir = opendir("tetriminos")) == NULL)
        exit(84);
    while ((current = readdir(dir)) != NULL) {
        if (my_strlen(current->d_name) > 2 && my_strcmp(".tetrimino",
            current->d_name))
            counter += 1;
    }
    closedir(dir);
    if (counter == 0)
        my_error_exit("No Tetriminos\n");
    return (counter);
}

char *get_name(char const *path)
{
    char *new;
    if (my_strlen(path) < 11)
        return (NULL);
    if ((new = malloc(sizeof(char) * (my_strlen(path) - 9))) == NULL)
        exit(84);
    new = my_strncpy(new, path, my_strlen(path) - 10);
    return (new);
}

char **get_array(char const *buffer, tetrimino *tetri)
{
    char **array = NULL;
    int i = 0;

    if ((array = malloc(sizeof(char *) * (tetri->size_y + 1))) == NULL)
        exit(84);
    array[tetri->size_y] = NULL;
    for (i = 0; i < tetri->size_y; i += 1) {
        if ((array[i] = malloc(sizeof(char) * (tetri->size_x + 1))) ==
            NULL)
            exit(84);
        for (int j = 0; j <= tetri->size_x; array[i][j] = '\0', j += 1);
    }
    for (i = 1; buffer[i - 1] != '\n'; i += 1);
    for (int j = 0; j < tetri->size_y; j += 1) {
        for (int k = 0; k < tetri->size_x && buffer[i] != '\n'; k += 1, i +=
            1) {
            array[j][k] = buffer[i];
        }
        i += 1;
    }
    return (array);
}

tetrimino get_info(char *bf, game *info)
{
    tetrimino tetri = null_tetri(bf);
    char *tm = NULL;
    int i = 0;
    int k = 0;
    if ((tm = malloc(sizeof(char) * 10)) == NULL) exit(84);
    for (int j = 0; j < 10; tm[j] = '\0', j += 1);
    for (; bf[i] && bf[i] != ' '; tm[k] = bf[i], k += 1, i += 1);
    if (!tetri.error && my_str_isnum(tm)) tetri.size_x = my_getnbr(tm);
    else tetri.error = 1;
    for (int j = 0; j < 10; tm[j] = '\0', j += 1);
    for (i += 1, k = 0; bf[i] && bf[i] != ' '; tm[k] = bf[i], k += 1, i += 1);
    if (!tetri.error && my_str_isnum(tm)) tetri.size_y = my_getnbr(tm);
    else tetri.error = 1;
    for (int j = 0; j < 10; tm[j] = '\0', j += 1);
    for (i += 1, k = 0; bf[i] && bf[i] != '\n'; tm[k] = bf[i], k += 1, i += 1);
    if (!tetri.error && my_str_isnum(tm)) tetri.color = my_getnbr(tm);
    else tetri.error = 1;
    if (!check_tetri(&tetri, bf, info)) tetri.array = get_array(bf, &tetri);
    free(tm);
    return (tetri);
}

void parse_tetrimino(game *info)
{
    int fd = 0;
    struct stat st;
    char buffer[200];
    char *path = NULL;
    info->count_tetri = count_tetri();
    char **paths = my_sort_str_array(create_array(info->count_tetri),
        info->count_tetri);
    if ((info->tetri = malloc(sizeof(tetrimino) * (info->count_tetri + 1)))
    == NULL) my_error_exit("malloc failed\n");
    for (int i = 0; i < info->count_tetri; i += 1, close(fd), free(path)) {
        path = my_malloc_strcat("./tetriminos/", paths[i]);
        if ((fd = open(path, O_RDONLY)) == -1) my_error_exit("READ");
        stat(path, &st);
        my_memset(buffer, 199, 0);
        read(fd, buffer, st.st_size);
        buffer[st.st_size] = '\0';
        info->tetri[i] = get_info(buffer, info);
        info->tetri[i].name = get_name(paths[i]);
    }
    for (int i = 0; paths[i]; i++) free(paths[i]);
    free(paths);
}