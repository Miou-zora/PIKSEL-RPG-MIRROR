/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_clock
*/

#include "struct_var.h"

int initialize_clock(clock_data_t **clock)
{
    (*clock) = malloc(sizeof(clock_data_t));
    if ((*clock) == NULL)
        return (84);
    (*clock)->clocksfInt64 = sfClock_create();
    if ((*clock)->clocksfInt64 == NULL)
        return (84);
    (*clock)->elapsed_time = 0;
    return (0);
}