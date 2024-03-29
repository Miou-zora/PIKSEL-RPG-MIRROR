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

const float NOT_SET = 0;
const float PI = 3.14159265358979323846;

int my_rpg(void)
{
    game_t *game = NULL;
    clock_data_t *principal_clock = create_clock_data();
    clock_data_t *clock_secondary = create_clock_data();

    srand(0);
    set_framerate_clock_data(clock_secondary, 0.03);
    set_framerate_clock_data(principal_clock, 0.03);
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
    sfRenderWindow_destroy(game->window);
    return (0);
}

int main(void)
{
    if (my_rpg() == 84)
        return (84);
}
