/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** verif_extension
*/

#include "stdbool.h"
#include <stddef.h>

bool verif_extension(char *filename, char *expected_extension)
{
    int i = 0;
    int j = 0;

    if (filename == NULL)
        return (false);
    if (expected_extension == NULL)
        return (true);
    while (filename[i] != '\0') {
        if (filename[i] == '.')
            j = i;
        i++;
    }
    for (i = 0; expected_extension[i] != '\0'
    && filename[i + j] != '\0'; i++) {
        if (filename[j + i] != expected_extension[i])
            return (false);
        i++;
    }
    return (true);
}