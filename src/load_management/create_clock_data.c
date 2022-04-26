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

    clock_data->clocksfInt64 = sfClock_create();
    clock_data->elapsed_time = 0;
    clock_data->currElapsedTime = (sfTime){0};
    clock_data->framerate = 0;
    return (clock_data);
}