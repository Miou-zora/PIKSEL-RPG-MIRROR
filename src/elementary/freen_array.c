/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** freen_array
*/

#include "struct_var.h"

void freen_array(void *array)
{
    void ***the_array = (void ***)array;

    if (*the_array == NULL)
        return;
    for (int i = 0; (*the_array)[i] != NULL; i++)
        freen(&((*the_array)[i]));
    freen(the_array);
}