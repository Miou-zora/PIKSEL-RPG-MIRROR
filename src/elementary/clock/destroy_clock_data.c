/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** destroy_clock_data
*/

#include "struct_var.h"

void destroy_clock_data(clock_data_t **clock_data)
{
    if (*clock_data) {
        if ((*clock_data)->clocksfInt64)
            sfClock_destroy((*clock_data)->clocksfInt64);
        freen(clock_data);
    }
}