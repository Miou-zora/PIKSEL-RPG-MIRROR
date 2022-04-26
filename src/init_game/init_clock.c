/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_clock
*/

#include "rpg.h"

int initialize_clock(my_clock_t **clock)
{
    (*clock) = malloc(sizeof(my_clock_t));
    if ((*clock) == NULL)
        return (84);
    (*clock)->clocksfInt64 = sfClock_create();
    if ((*clock)->clocksfInt64 == NULL)
        return (84);
    (*clock)->elapsed_time = 0;
    return (0);
}