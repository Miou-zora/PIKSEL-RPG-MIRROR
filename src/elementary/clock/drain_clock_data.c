/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** drain_clock_data
*/

#include "struct_var.h"

void drain_clock_data(clock_data_t *clock)
{
    if (clock == NULL)
        return;
    clock->currElapsedTime = sfClock_restart(clock->clocksfInt64);
    clock->elapsed_time += clock->currElapsedTime.microseconds;
}
