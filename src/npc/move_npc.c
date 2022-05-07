/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** move_npc
*/

#include "my.h"
#include "struct_var.h"

void move_npc_left(game_t *game, int speed)
{
    for (int i = 0; i != 4; i++) {
        if (game->npc[i]->display == true) {
            game->npc[i]->sprite_data->pos.x += 20 * speed;
            sfSprite_setPosition(game->npc[i]->sprite_data->sprite,
            game->npc[i]->sprite_data->pos);
        }
    }
}

void move_npc_right(game_t *game, int speed)
{
    for (int i = 0; i != 4; i++) {
        if (game->npc[i]->display == true) {
            game->npc[i]->sprite_data->pos.x -= 20 * speed;
            sfSprite_setPosition(game->npc[i]->sprite_data->sprite,
            game->npc[i]->sprite_data->pos);
        }
    }
}