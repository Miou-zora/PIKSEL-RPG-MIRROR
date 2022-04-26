/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** destroy_animator
*/

#include "struct_var.h"

void destroy_animator(animator_t **animator)
{
    if (*animator) {
        if ((*animator)->sprite_data)
            destroy_sprite_data(&(*animator)->sprite_data);
        if ((*animator)->clock_data)
            destroy_clock_data(&(*animator)->clock_data);
        freen(animator);
    }
}