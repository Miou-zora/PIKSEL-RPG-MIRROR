/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_nest_particle
*/

#include "struct_var.h"
#include "my.h"
#include "math.h"

void update_particle(particle_t *particle, float delta_time)
{
    float x_speed = particle->speed * cos(particle->acceleration);
    float y_speed = particle->speed * sin(particle->acceleration);

    particle->position.x += x_speed * delta_time;
    particle->position.y += y_speed * delta_time;
    // my_printf("%i\n", (int)( (particle->speed - 1.f) * 100));
    particle->acceleration += delta_time / 50 * (particle->speed - 0.5f);
}

void update_nest_particle(nest_particle_t *nest_particle, float delta_time)
{
    particle_t *cursor = NULL;

    if (nest_particle == NULL)
        return;
    cursor = nest_particle->all_particles;
    while (cursor != NULL) {
        update_particle(cursor, delta_time);
        cursor = cursor->next;
    }
}
