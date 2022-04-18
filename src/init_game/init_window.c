/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** init sprite and data in rpg
*/

#include "my.h"
#include "rpg.h"

int initialize_window(game_t *game)
{
    game->mode = (sfVideoMode){1080, 1920, 32};
    game->window = sfRenderWindow_create(game->mode, "my_defender", sfResize |
    sfClose, NULL);
    if (game->window == NULL)
        return (84);
    return (0);
}