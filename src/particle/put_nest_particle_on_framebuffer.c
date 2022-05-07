/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** put_nest_particle_on_framebuffer
*/

#include "struct_var.h"
#include <math.h>
#include "my.h"

int aezrazer(int a, int b)
{
    return (a > b ? a : b);
}

void put_particle_on_framebuffer(particle_t *particle,
framebuffer_t *framebuffer, sfVector2f offset, sfColor color)
{
    sfVector2i pixel_pos = {0, 0};
    // sfColor color = {255, 255, 255, 255};

    if (particle == NULL || framebuffer == NULL)
        return;
    pixel_pos.x = (int)(particle->position.x + offset.x);
    pixel_pos.y = (int)(particle->position.y + offset.y);
    if (pixel_pos.x < 0 || pixel_pos.x >= (int)framebuffer->width ||
    pixel_pos.y < 0 || pixel_pos.y >= (int)framebuffer->height) {
        return;
    }
    float distance = sqrt(pow(particle->position.x, 2) + pow(particle->position.y, 2));
    float pourcent = pow((distance * 100.f / (framebuffer->height / 2)) / 100.f, 2);
    if (pourcent > 1) {
        pourcent = 1;
    }
    color.r *= (1 - pourcent);
    color.g *= (1 - pourcent);
    color.b *= (1 - pourcent);
    color.a *= (1 - pourcent);
    framebuffer->pixels[(pixel_pos.x + pixel_pos.y * framebuffer->width) * 4 + 0] = color.r;
    framebuffer->pixels[(pixel_pos.x + pixel_pos.y * framebuffer->width) * 4 + 1] = color.g;
    framebuffer->pixels[(pixel_pos.x + pixel_pos.y * framebuffer->width) * 4 + 2] = color.b;
    framebuffer->pixels[(pixel_pos.x + pixel_pos.y * framebuffer->width) * 4 + 3] = color.a;
}

void put_nest_particle_on_framebuffer(nest_particle_t *nest_particle)
{
    particle_t *cursor = NULL;

    if (nest_particle == NULL || nest_particle->framebuffer == NULL)
        return;
    cursor = nest_particle->all_particles;
    while (cursor != NULL) {
        put_particle_on_framebuffer(cursor, nest_particle->framebuffer,
        nest_particle->offset, nest_particle->color);
        cursor = cursor->next;
    }
}
