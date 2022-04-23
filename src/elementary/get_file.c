/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** get_file
*/

#include <stdio.h>
#include "struct_var.h"

char *get_file(char *path)
{
    char *buffer = NULL;
    size_t size = 0;
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        put_str_error("Unable to open file:");
        put_str_error(path);
        return (NULL);
    }
    getline(&buffer, &size, file);
    fclose(file);
    return (buffer);
}