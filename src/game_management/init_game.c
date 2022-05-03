/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_game
*/

#include "struct_var.h"
#include "my.h"

bool fill_game(game_t *game)
{
    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "Piksel RPG", sfClose, NULL);
    if (game->window == NULL)
        return (true);
    // game->enemy = load_enemy("scripts/ennemy/wolf.ene");
    // if (game->enemy == NULL)
    //     return (true);
    game->background = my_calloc(1, sizeof(background_t));
    if (game->background == NULL)
        return (true);
    game->background->scene_background = MENU;
    if (initialize_menu(&(game->background->menu)) == true)
        return (true);
    if (init_back(game->background)) {
        return (true);
    }
    return (false);
}

bool initialize_game(game_t **game)
{
    if (game == NULL)
        return (true);
    (*game) = my_calloc(1, sizeof(*(*game)));
    if ((*game) == NULL)
        return (true);
    if (fill_game(*game) == true) {
        // destroy_game
        return (true);
    }
    return (false);
}