/*
** EPITECH PROJECT, 2022
** display_sprite
** File description:
** display_sprite
*/

#include "struct_var.h"
#include "rpg.h"

void display(player_t *player)
{
    if (detect_if_key_pressed(player) == 1)
        sfRenderWindow_drawSprite(player->window, player->iddle->sprite_data->sprite, NULL);
    if (player->player_mode == 1 && detect_if_key_pressed(player) == 0)
        sfRenderWindow_drawSprite(player->window, player->walk->sprite_data->sprite, NULL);
    if (player->player_mode == 2 && detect_if_key_pressed(player) == 0)
        sfRenderWindow_drawSprite(player->window, player->run->sprite_data->sprite, NULL);
}
