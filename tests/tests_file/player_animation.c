/*
** EPITECH PROJECT, 2022
** player_animation
** File description:
** player_animation
*/

#include "struct_var.h"

void player_animation_run(player_t *player)
{
    player->run->sprite_data->rect.left += 48;
    if (player->run->sprite_data->rect.left == 288)
        player->run->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->run->sprite_data->sprite);
    sfSprite_setTextureRect(player->run->sprite_data->sprite,
    player->run->sprite_data->rect);
}

void player_animation_walk(player_t *player)
{
    player->walk->sprite_data->rect.left += 48;
    if (player->walk->sprite_data->rect.left == 288)
        player->walk->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->walk->sprite_data->sprite);
    sfSprite_setTextureRect(player->walk->sprite_data->sprite,
    player->walk->sprite_data->rect);
}

void player_animation_iddle(player_t *player)
{
    player->iddle->sprite_data->rect.left += 48;
    if (player->iddle->sprite_data->rect.left == 288)
        player->iddle->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->iddle->sprite_data->sprite);
    sfSprite_setTextureRect(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->rect);
}
