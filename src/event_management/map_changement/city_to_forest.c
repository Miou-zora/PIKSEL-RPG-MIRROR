/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** city_to_forest
*/

#include "struct_var.h"
#include "my.h"

bool city_to_forest(game_t *game)
{
    if (game->player->traveled_distance > 515
    && game->player->traveled_distance < 545
    && game->background->scene_background == CITY
    && game->npc[1]->display_text == true) {
        game->background->scene_background = FOREST;
        game->npc[1]->display_text = false;
        game->player->traveled_distance = 0;
        game->player->pos = (sfVector2f){820, 440};
        return (true);
    }
    if (game->player->traveled_distance > 515
    && game->player->traveled_distance < 545
    && game->background->scene_background == CITY) {
        game->npc[1]->display_text = true;
        return (true);
    }
    return (false);
}