/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** freen
*/

#include <stdlib.h>
#include <stddef.h>

void freen(void *ptr)
{
    void **the_ptr = (void **)ptr;

    free(*the_ptr);
    *the_ptr = NULL;
}