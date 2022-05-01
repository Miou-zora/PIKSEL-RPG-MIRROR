/*
** EPITECH PROJECT, 2022
** player_animation_attack
** File description:
** player_animation_attack
*/

#include "struct_var.h"
#include "rpg.h"

void player_animation_sword(player_t *player)
{
    player->sword->sprite_data->rect.left += 48;
    if (player->sword->sprite_data->rect.left == 576) {
        player->sword->sprite_data->rect.left = 0;
        player->attack = false;
    }
    sfSprite_getTextureRect(player->sword->sprite_data->sprite);
    sfSprite_setTextureRect(player->sword->sprite_data->sprite,
    player->sword->sprite_data->rect);
}

void player_animation_gun(player_t *player)
{
    player->gun->sprite_data->rect.left += 48;
    if (player->gun->sprite_data->rect.left == 192) {
        player->gun->sprite_data->rect.left = 0;
        player->attack = false;
    }
    sfSprite_getTextureRect(player->gun->sprite_data->sprite);
    sfSprite_setTextureRect(player->gun->sprite_data->sprite,
    player->gun->sprite_data->rect);
}

void player_animation_punch(player_t *player)
{
    player->punch->sprite_data->rect.left += 48;
    if (player->punch->sprite_data->rect.left == 480) {
        player->punch->sprite_data->rect.left = 0;
        player->attack = false;
    }
    sfSprite_getTextureRect(player->punch->sprite_data->sprite);
    sfSprite_setTextureRect(player->punch->sprite_data->sprite,
    player->punch->sprite_data->rect);
}

void player_animation_spear(player_t *player)
{
    player->spear->sprite_data->rect.left += 54;
    if (player->spear->sprite_data->rect.left == 486) {
        player->spear->sprite_data->rect.left = 0;
        player->attack = false;
    }
    sfSprite_getTextureRect(player->spear->sprite_data->sprite);
    sfSprite_setTextureRect(player->spear->sprite_data->sprite,
    player->spear->sprite_data->rect);
}