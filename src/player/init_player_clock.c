/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_player_clock
*/

#include "my.h"
#include "struct_var.h"

bool init_player_animator_move_walk(player_t *player)
{
    player->walk = load_animator("scripts/animator/walk_player.ani");
    if (player->walk == NULL)
        return (true);
    player->walk->sprite_data->scale = (sfVector2f){6, 6};
    sfSprite_setScale(player->walk->sprite_data->sprite,
    player->walk->sprite_data->scale);
    player->run = load_animator("scripts/animator/run_player.ani");
    if (player->run == NULL)
        return (true);
    player->run->sprite_data->scale = (sfVector2f){6, 6};
    sfSprite_setScale(player->run->sprite_data->sprite,
    player->run->sprite_data->scale);
    return (false);
}

bool init_player_animator_move(player_t *player)
{
    if (init_player_animator_move_walk(player))
        return (true);
    player->iddle = load_animator("scripts/animator/iddle_player.ani");
    if (player->iddle == NULL)
        return (true);
    player->iddle->sprite_data->pos = (sfVector2f){400, 400};
    player->iddle->sprite_data->scale = (sfVector2f){6, 6};
    sfSprite_setPosition(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->pos);
    sfSprite_setScale(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->scale);
    return (false);
}

bool init_player_clock_weapon(player_t *player)
{
    player->c_gun = create_clock_data();
    if (player->c_gun == NULL)
        return (true);
    player->c_punch = create_clock_data();
    if (player->c_punch == NULL)
        return (true);
    player->c_spear = create_clock_data();
    if (player->c_spear == NULL)
        return (true);
    player->c_sword = create_clock_data();
    if (player->c_sword == NULL)
        return (true);
    return (false);
}

bool init_player_clock(player_t *player)
{
    if (init_player_clock_weapon(player))
        return (true);
    player->anim = create_clock_data();
    if (player->anim == NULL)
        return (true);
    player->player = create_clock_data();
    if (player->player == NULL)
        return (true);
    player->clock_update_animator = create_clock_data();
    if (player->clock_update_animator == NULL)
        return (true);
    set_framerate_clock_data(player->clock_update_animator, 0.1);
    return (false);
}