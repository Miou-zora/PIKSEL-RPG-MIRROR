/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "struct_var.h"

void shade_framebuffer(framebuffer_t *framebuffer) {
    for (unsigned int i = 0; i < framebuffer->width * framebuffer->height * 4; i++) {
        framebuffer->pixels[i] -= (framebuffer->pixels[i] > 0) ? 1 : 0;
    }
}

int my_rpg(void)
{
    srand(0);
    game_t *game = NULL;
    clock_data_t *principal_clock = create_clock_data();
    // sfTexture *texture = sfTexture_create(1920, 1080);
    // sfSprite *sprite = sfSprite_create();
    // nest_particle_t *nest_particle = create_nest_particle(100, (sfVector2i){1920, 1080});

    set_framerate_clock_data(principal_clock, 1000000 / 60);
    if (initialize_game(&game))
        return (84);
    while (sfRenderWindow_isOpen(game->window)) {
        drain_clock_data(principal_clock);
        while (update_clock_data(principal_clock)) {
            // update_nest_particle(nest_particle, 1);
            // update_nest_particle(enest_particle, 1);
            // shade_framebuffer(nest_particle->framebuffer);
            // put_nest_particle_on_framebuffer(nest_particle);
            // put_nest_particle_on_framebuffer(enest_particle, framebuffer);
            // sfTexture_updateFromPixels(texture, nest_particle->framebuffer->pixels, 1920, 1080, 0, 0);
            // sfSprite_setTexture(sprite, texture, sfTrue);
            event_handler(game);
            update(game);
            display(game);
            // sfRenderWindow_drawSprite(game->window, sprite, NULL);
            // sfRenderWindow_display(game->window);
        }
    }
    return (0);
}

int main(void)
{
    if (my_rpg() == 84)
        return (84);
}
