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
