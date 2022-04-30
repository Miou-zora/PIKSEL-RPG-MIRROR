/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** update_clock_data
*/

#include "struct_var.h"

bool update_clock_data(clock_data_t *clock)
{
    if (clock == NULL)
        return (false);
    if (clock->elapsed_time > clock->framerate) {
        clock->elapsed_time -= clock->framerate;
        return (true);
    }
    return (false);
}