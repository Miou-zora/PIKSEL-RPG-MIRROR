/*
** EPITECH PROJECT, 2022
** clock_cinematic
** File description:
** update_clock_cinematic
*/

#include "struct_var.h"
#include "my.h"

void clock_cine_anim_player(cinematic_t *cinematic)
{
    drain_clock_data(cinematic->anim_player_walk->clock_data);
    while (update_clock_data(cinematic->anim_player_walk->clock_data)) {
        if (cinematic->anim_enemy_run->sprite_data->pos.x >=
        cinematic->anim_player_walk->sprite_data->pos.x)
            cinematic->anim_player_walk->sprite_data->rect.left = 0;
        else
            cinematic->anim_player_walk->sprite_data->rect.left += 48;
        if (cinematic->anim_player_walk->sprite_data->rect.left == 288)
            cinematic->anim_player_walk->sprite_data->rect.left = 0;
        sfSprite_setTextureRect
        (cinematic->anim_player_walk->sprite_data->sprite,
        cinematic->anim_player_walk->sprite_data->rect);
    }
}

void clock_cine_anim_enemy(cinematic_t *cinematic)
{
    drain_clock_data(cinematic->anim_enemy_run->clock_data);
    while (update_clock_data(cinematic->anim_enemy_run->clock_data)) {
        cinematic->anim_enemy_run->sprite_data->rect.left += 48;
        if (cinematic->anim_enemy_run->sprite_data->rect.left == 288)
            cinematic->anim_enemy_run->sprite_data->rect.left = 0;
        sfSprite_setTextureRect
        (cinematic->anim_enemy_run->sprite_data->sprite,
        cinematic->anim_enemy_run->sprite_data->rect);
    }
}

void clock_cine_move_player(cinematic_t *cinematic)
{
    drain_clock_data(cinematic->clock_move_player);
    while (update_clock_data(cinematic->clock_move_player)) {
        if (cinematic->anim_enemy_run->sprite_data->pos.x >=
        cinematic->anim_player_walk->sprite_data->pos.x)
            cinematic->anim_player_walk->sprite_data->pos.x += 0;
        else
            cinematic->anim_player_walk->sprite_data->pos.x -= 5;
        sfSprite_setPosition(cinematic->anim_player_walk->sprite_data->sprite,
        cinematic->anim_player_walk->sprite_data->pos);
        cinematic->anim_player_walk->sprite_data->pos =
        sfSprite_getPosition
        (cinematic->anim_player_walk->sprite_data->sprite);
    }
}

void clock_cine_move_enemy(cinematic_t *cinematic)
{
    drain_clock_data(cinematic->clock_move_enemy);
    while (update_clock_data(cinematic->clock_move_enemy)) {
            cinematic->anim_enemy_run->sprite_data->pos.x += 8;
        sfSprite_setPosition(cinematic->anim_enemy_run->sprite_data->sprite,
        cinematic->anim_enemy_run->sprite_data->pos);
        cinematic->anim_enemy_run->sprite_data->pos =
        sfSprite_getPosition(cinematic->anim_enemy_run->sprite_data->sprite);
    }
}

void call_clock_cine(cinematic_t *cinematic)
{
    clock_cine_anim_player(cinematic);
    clock_cine_anim_enemy(cinematic);
    clock_cine_move_player(cinematic);
    clock_cine_move_enemy(cinematic);
}