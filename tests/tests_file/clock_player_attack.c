/*
** EPITECH PROJECT, 2022
** clock_player_attack
** File description:
** clock_player_attack
*/

#include "struct_var.h"
#include "rpg.h"

void clock_animation_sword(player_t *player)
{
    player->c_sword->time = sfClock_getElapsedTime(player->c_sword->clock);
    player->c_sword->seconds = player->c_sword->time.microseconds / 1000000.0;
    if (player->c_sword->seconds > 0.04 && player->attack == true &&
    player->weapon == 1) {
        if (player->direction == true)
            player->sword->sprite_data->rect.top = 0;
        else if (player->direction == false)
            player->sword->sprite_data->rect.top = 48;
        sfSprite_getTextureRect(player->sword->sprite_data->sprite);
        sfSprite_setTextureRect(player->sword->sprite_data->sprite,
        player->sword->sprite_data->rect);
        player_animation_sword(player);
        sfClock_restart(player->c_sword->clock);
    }
}

void clock_animation_spear(player_t *player)
{
    player->c_spear->time = sfClock_getElapsedTime(player->c_spear->clock);
    player->c_spear->seconds = player->c_spear->time.microseconds / 1000000.0;
    if (player->c_spear->seconds > 0.08 && player->attack == true &&
    player->weapon == 2) {
        if (player->direction == true)
            player->spear->sprite_data->rect.top = 0;
        else if (player->direction == false)
            player->spear->sprite_data->rect.top = 48;
        sfSprite_getTextureRect(player->spear->sprite_data->sprite);
        sfSprite_setTextureRect(player->spear->sprite_data->sprite,
        player->spear->sprite_data->rect);
        player_animation_spear(player);
        sfClock_restart(player->c_spear->clock);
    }
}

void clock_animation_punch(player_t *player)
{
    player->c_punch->time = sfClock_getElapsedTime(player->c_punch->clock);
    player->c_punch->seconds = player->c_punch->time.microseconds / 1000000.0;
    if (player->c_punch->seconds > 0.08 && player->attack == true &&
    player->weapon == 3) {
        if (player->direction == true)
            player->punch->sprite_data->rect.top = 0;
        else if (player->direction == false)
            player->punch->sprite_data->rect.top = 48;
        sfSprite_getTextureRect(player->punch->sprite_data->sprite);
        sfSprite_setTextureRect(player->punch->sprite_data->sprite,
        player->punch->sprite_data->rect);
        player_animation_punch(player);
        sfClock_restart(player->c_punch->clock);
    }
}

void clock_animation_gun(player_t *player)
{
    player->c_gun->time = sfClock_getElapsedTime(player->c_gun->clock);
    player->c_gun->seconds = player->c_gun->time.microseconds / 1000000.0;
    if (player->c_gun->seconds > 0.08 && player->attack == true &&
    player->weapon == 4) {
        if (player->direction == true)
            player->gun->sprite_data->rect.top = 0;
        else if (player->direction == false)
            player->gun->sprite_data->rect.top = 48;
        sfSprite_getTextureRect(player->gun->sprite_data->sprite);
        sfSprite_setTextureRect(player->gun->sprite_data->sprite,
        player->gun->sprite_data->rect);
        player_animation_gun(player);
        sfClock_restart(player->c_gun->clock);
    }
}

void called_clock_player_attack(player_t *player)
{
    clock_animation_sword(player);
    clock_animation_gun(player);
    clock_animation_spear(player);
    clock_animation_punch(player);
}