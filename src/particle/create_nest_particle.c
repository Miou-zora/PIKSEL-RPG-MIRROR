/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_nest_particle
*/

#include "struct_var.h"
#include "my.h"

static particle_t *create_particle(particle_t *particle)
{
    particle_t *new_particle = my_calloc(1, sizeof(*new_particle));

    if (new_particle) {
        new_particle->acceleration = 2.f * PI * (float)(rand() % 1000) / 1000;
        new_particle->speed = ((float)(rand() % 1000)) / 1000;
        new_particle->speed *= new_particle->speed * new_particle->speed * 2;
        new_particle->position = (sfVector2f){0, 0};
        new_particle->next = particle;
        new_particle->color = (sfColor){rand() % 255, rand() % 255,
        rand() % 255, 255};
        new_particle->prev = NULL;
        if (particle)
            new_particle->prev = particle->prev;
    }
    return (new_particle);
}

nest_particle_t *create_nest_particle(int number_of_particle,
sfVector2i size_framebuffer)
{
    nest_particle_t *nest_particle = my_calloc(1, sizeof(*nest_particle));
    my_printf("creat nest\n");
    if (nest_particle == NULL)
        return (NULL);
    nest_particle->framebuffer = create_framebuffer(size_framebuffer.x,
    size_framebuffer.y);
    if (nest_particle->framebuffer == NULL)
        return (NULL);
    nest_particle->offset = (sfVector2f){size_framebuffer.x / 2,
    size_framebuffer.y / 2};
    nest_particle->all_particles = NULL;
    for (int i = 0; i < number_of_particle; i++) {
        nest_particle->all_particles =
        create_particle(nest_particle->all_particles);
    }
    return (nest_particle);
}
