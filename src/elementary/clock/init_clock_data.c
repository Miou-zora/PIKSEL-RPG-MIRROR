/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_clock_data
*/

#include "struct_var.h"
#include "my.h"

clock_data_t *init_clock_data(float framerate_seconds)
{
    clock_data_t *clock_data = my_calloc(1, sizeof(*clock_data));
    my_printf("read clock\n");
    if (clock_data == NULL)
        return (NULL);
    clock_data->clock = sfClock_create();
    if (clock_data->clock == NULL) {
        freen(&clock_data);
        return (NULL);
    }
    clock_data->elapsed_time = 0;
    clock_data->framerate_seconds = framerate_seconds;
    return (clock_data);
}
