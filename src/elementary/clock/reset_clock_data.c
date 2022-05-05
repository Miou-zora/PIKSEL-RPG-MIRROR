/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** reset_clock_data
*/

#include "struct_var.h"

void reset_clock_data(clock_data_t *clock)
{
    if (clock == NULL)
        return;
    sfClock_restart(clock->clock);
    clock->elapsed_time = 0;
}
