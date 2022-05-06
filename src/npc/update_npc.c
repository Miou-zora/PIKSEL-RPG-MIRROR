/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** update_npc
*/

#include "my.h"
#include "struct_var.h"

void update_npc(game_t *game)
{
    for (int i = 0; i != 4; i++) {
        if (game->background->scene_background == game->npc[i]->scene
        && game->npc[i]->distance_à_parcourir - 60 < game->player->traveled_distance
        && game->npc[i]->distance_à_parcourir + 60 > game->player->traveled_distance) {
            game->npc[i]->display = true;
        } else {
            game->npc[i]->display = false;
        }
    }
}