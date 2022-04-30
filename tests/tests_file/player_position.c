/*
** EPITECH PROJECT, 2022
** player_position
** File description:
** player_position
*/

#include "struct_var.h"

void update_position(player_t *player)
{
    sfSprite_setPosition(player->run->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->walk->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->iddle->sprite_data->sprite, player->pos);
}
