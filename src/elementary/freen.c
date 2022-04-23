/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** freen
*/

#include <stdlib.h>
#include <stddef.h>

void freen(void **ptr)
{
    free(*ptr);
    *ptr = NULL;
}