/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "struct_var.h"

int my_rpg(void)
{
    game_t *game = NULL;
    clock_data_t *principal_clock = create_clock_data();

    set_framerate_clock_data(principal_clock, 1000000 / 60);
    if (initialize_game(&game))
        return (84);
    while (sfRenderWindow_isOpen(game->window)) {
        drain_clock_data(principal_clock);
        while (update_clock_data(principal_clock)) {
            event_handler(game);
        }
    }
    return (0);
}

int main(void)
{
    if (my_rpg() == 84)
        return (84);
}