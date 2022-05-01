/*
** EPITECH PROJECT, 2022
** clock_player
** File description:
** clock_player
*/

#include "struct_var.h"
#include "rpg.h"

void clock_player(player_t *player)
{
    player->player->time = sfClock_getElapsedTime(player->player->clock);
    player->player->seconds = player->player->time.microseconds;
    sfClock_restart(player->player->clock);
    move_player_walk(player);
    move_player_run(player);
    update_position(player);
    while (player->player->seconds > 1000000.0) {
        player->player->seconds -= 1000000.0;
    }
}

void clock_animation_player(player_t *player)
{
    player->anim->time = sfClock_getElapsedTime(player->anim->clock);
    player->anim->seconds = player->anim->time.microseconds / 1000000.0;
    if (player->anim->seconds > 0.08) {
        if (detect_if_key_pressed(player) == 1)
            player_animation_iddle(player);
        if (player->player_mode == 1 && detect_if_key_pressed(player) == 0)
            player_animation_walk(player);
        if (player->player_mode == 2 && detect_if_key_pressed(player) == 0)
            player_animation_run(player);
        sfClock_restart(player->anim->clock);
    }
}

void clock_animation_sword(player_t *player)
{
    player->c_sword->time = sfClock_getElapsedTime(player->c_sword->clock);
    player->c_sword->seconds = player->c_sword->time.microseconds / 1000000.0;
    if (player->c_sword->seconds > 0.04) {
        if (player->attack == true)
            player_animation_sword(player);
        sfClock_restart(player->c_sword->clock);
    }
}

void clock_animation_gun(player_t *player)
{
    player->c_gun->time = sfClock_getElapsedTime(player->c_gun->clock);
    player->c_gun->seconds = player->c_gun->time.microseconds / 1000000.0;
    if (player->c_gun->seconds > 0.08) {
        if (player->attack == true)
            player_animation_gun(player);
        sfClock_restart(player->c_gun->clock);
    }
}

void clock_animation_punch(player_t *player)
{
    player->c_punch->time = sfClock_getElapsedTime(player->c_punch->clock);
    player->c_punch->seconds = player->c_punch->time.microseconds / 1000000.0;
    if (player->c_punch->seconds > 0.08) {
        if (player->attack == true)
            player_animation_punch(player);
        sfClock_restart(player->c_punch->clock);
    }
}

void clock_animation_spear(player_t *player)
{
    player->c_spear->time = sfClock_getElapsedTime(player->c_spear->clock);
    player->c_spear->seconds = player->c_spear->time.microseconds / 1000000.0;
    if (player->c_spear->seconds > 0.08) {
        if (player->attack == true)
            player_animation_spear(player);
        sfClock_restart(player->c_spear->clock);
    }
}

void called_clock(player_t *player)
{
    clock_player(player);
    clock_animation_player(player);
    clock_animation_sword(player);
    clock_animation_gun(player);
    clock_animation_punch(player);
    clock_animation_spear(player);
}
