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
    clock->elapsed_time += sfClock_restart(clock->clock).microseconds;
}
