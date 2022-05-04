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
    clock_data_t *clock_secondary = create_clock_data();

    set_framerate_clock_data(clock_secondary, 0.1);
    set_framerate_clock_data(principal_clock, 0.1);
    if (initialize_game(&game))
        return (84);
    game->clock_secondary = clock_secondary;
    while (sfRenderWindow_isOpen(game->window)) {
        drain_clock_data(principal_clock);
        while (update_clock_data(principal_clock)) {
            event_handler(game);
            update(game);
            display(game);
        }
    }
    return (0);
}

int main(void)
{
    if (my_rpg() == 84)
        return (84);
}
