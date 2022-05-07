/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** get_file
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

FILE *fs_open_file(char const *filepath)
{
    FILE *file_descriptor = fopen(filepath, "r");

    if (file_descriptor == NULL) {
        return (file_descriptor);
    } else {
        return (file_descriptor);
    }
}

int get_len_file(char const *filepath)
{
    FILE *fd = fs_open_file(filepath);
    int len_file = 0;
    int len_line = 0;
    size_t line_buf_size = 0;
    char *line_buf = NULL;

    if (fd == NULL) {
        return (-1);
    }
    len_line = getline(&line_buf, &line_buf_size, fd);
    len_file += len_line;
    while (len_line >= 0) {
        len_line = getline(&line_buf, &line_buf_size, fd);
        len_file += len_line;
    }
    free(line_buf);
    line_buf = NULL;
    fclose(fd);
    return (len_file);
}

void del_if_null(char *buffer, FILE *fd)
{
    if (buffer != NULL)
        free(buffer);
    if (fd != NULL)
        fclose(fd);
}

char *get_file(char const *filepath)
{
    int len_file = get_len_file(filepath);
    FILE *fd = fs_open_file(filepath);
    char *buffer = my_calloc(len_file + 2, sizeof(*buffer));
    char *line_buf = NULL;
    int len_line = 0;
    size_t line_buf_size = 0;

    if (fd == NULL || len_file == -1) {
        del_if_null(buffer, fd);
        return (NULL);
    }
    len_line = getline(&line_buf, &line_buf_size, fd);
    while (len_line >= 0) {
        my_strcat(buffer, line_buf);
        len_line = getline(&line_buf, &line_buf_size, fd);
    }
    free(line_buf);
    fclose(fd);
    return (buffer);
}