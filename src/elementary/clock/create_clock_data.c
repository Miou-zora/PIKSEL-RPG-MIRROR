/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_clock_data
*/

#include "struct_var.h"
#include "stdlib.h"

clock_data_t *create_clock_data(void)
{
    clock_data_t *clock_data = malloc(sizeof(*clock_data));

    clock_data->clock = sfClock_create();
    clock_data->elapsed_time = NOT_SET;
    clock_data->framerate_seconds = NOT_SET;
    return (clock_data);
}
