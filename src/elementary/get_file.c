/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** get_file
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>

char *get_file(char *filepath)
{
    FILE *stream = NULL;
    char *buff;
    size_t len = 0;

    stream = fopen(filepath, "r");
    if (stream == NULL) {
        return (NULL);
    }
    if (getline(&buff, &len, stream) == -1) {
        return (NULL);
    }
    fclose(stream);
    return (buff);
}