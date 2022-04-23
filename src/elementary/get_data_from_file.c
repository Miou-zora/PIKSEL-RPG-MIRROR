/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** get_data_from_file
*/

#include "my.h"
#include "struct_var.h"

char **get_data_from_file(char *path)
{
    char *file = get_file(path);
    char **data = NULL;

    if (file == NULL)
        return (NULL);
    data = data_to_array_str(file, "\n");
    return (data);
}