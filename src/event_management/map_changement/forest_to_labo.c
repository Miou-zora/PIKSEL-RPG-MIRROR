/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** forest_to_labo
*/

#include "struct_var.h"
#include "my.h"

bool forest_to_labo(game_t *game)
{
    if (game->player->traveled_distance > 470
    && game->player->traveled_distance < 500
    && game->background->scene_background == FOREST) {
        game->background->scene_background = LABO;
        game->player->traveled_distance = 0;
    }
    return (false);
}