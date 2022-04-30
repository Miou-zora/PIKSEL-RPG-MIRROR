/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** set_framerate_clock_data
*/

#include "struct_var.h"

void set_framerate_clock_data(clock_data_t *clock, int framerate)
{
    if (clock == NULL)
        return;
    clock->framerate = framerate;
}
