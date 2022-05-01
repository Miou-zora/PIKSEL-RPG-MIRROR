/*
** EPITECH PROJECT, 2022
** display_sprite
** File description:
** display_sprite
*/

#include "struct_var.h"
#include "rpg.h"

void display_move_player(player_t *player)
{
    if (detect_if_key_pressed(player) == 1)
        sfRenderWindow_drawSprite(player->window, player->iddle->sprite_data->sprite, NULL);
    if (player->player_mode == 1 && detect_if_key_pressed(player) == 0)
        sfRenderWindow_drawSprite(player->window, player->walk->sprite_data->sprite, NULL);
    if (player->player_mode == 2 && detect_if_key_pressed(player) == 0)
        sfRenderWindow_drawSprite(player->window, player->run->sprite_data->sprite, NULL);
}

void display_attack_player(player_t *player)
{
    if (player->weapon == 1)
        sfRenderWindow_drawSprite(player->window, player->sword->sprite_data->sprite, NULL);
    if (player->weapon == 2)
        sfRenderWindow_drawSprite(player->window, player->spear->sprite_data->sprite, NULL);
    if (player->weapon == 3)
        sfRenderWindow_drawSprite(player->window, player->punch->sprite_data->sprite, NULL);
    if (player->weapon == 4)
        sfRenderWindow_drawSprite(player->window, player->gun->sprite_data->sprite, NULL);
}

void display_player_sprites(player_t *player)
{
    if (player->attack == false)
        display_move_player(player);
    if (player->attack == true)
        display_attack_player(player);
}