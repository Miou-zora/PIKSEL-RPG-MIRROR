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
    if (game->player->traveled_distance > 478
    && game->player->traveled_distance < 520
    && game->background->scene_background == FOREST
    && game->npc[3]->display_text == true) {
        game->npc[3]->display_text = false;
        game->background->scene_background = LABO;
        game->player->traveled_distance = 0;
    }
    if (game->player->traveled_distance > 478
    && game->player->traveled_distance < 520
    && game->background->scene_background == FOREST) {
        game->npc[3]->display_text = true;
    }
    return (false);
}