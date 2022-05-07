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
        if ((*clock_data)->clock)
            sfClock_destroy((*clock_data)->clock);
        freen(clock_data);
    }
}
