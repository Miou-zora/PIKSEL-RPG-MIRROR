/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** destroy_nest_particle
*/

#include "struct_var.h"

void destroy_nest_particle(nest_particle_t **nest_particle)
{
    particle_t *cursor = NULL;

    if (nest_particle == NULL || (*nest_particle) == NULL)
        return;
    cursor = (*nest_particle)->all_particles;
    while (cursor != NULL) {
        if (cursor->prev != NULL)
            freen(&(cursor->prev));
        if (cursor->next == NULL)
            freen(&cursor);
        else
            cursor = cursor->next;
    }
    freen(&((*nest_particle)->framebuffer->pixels));
    freen(&((*nest_particle)->framebuffer));
    freen(nest_particle);
}
