/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** display_npc
*/

#include "my.h"
#include "struct_var.h"

void display_npc(game_t *game)
{
    for (int i = 0; i != 4; i++) {
        if (game->background->scene_background == game->npc[i]->scene
        && game->npc[i]->display == true)
            sfRenderWindow_drawSprite(game->window, game->npc[i]->sprite_data->sprite, NULL);
        if (game->npc[i]->display_text == true) {
            display_text_zone(game->window, game->npc[i]->dialogue);
        }
    }
}