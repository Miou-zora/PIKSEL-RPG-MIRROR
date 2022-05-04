/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_player
*/

#include "my.h"
#include "struct_var.h"

bool init_player_clock(player_t *player)
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
    player->anim = create_clock_data();
    if (player->anim == NULL)
        return (true);
    player->player = create_clock_data();
    if (player->player == NULL)
        return (true);
    return (false);
}

bool init_player_animator_move(player_t *player)
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

bool init_player_animator(player_t *player)
{

    player->gun = load_animator("scripts/animator/gun_player.ani");
    if (player->gun == NULL)
        return (true);
    player->gun->sprite_data->scale = (sfVector2f){6, 6};
    sfSprite_setScale(player->gun->sprite_data->sprite,
    player->gun->sprite_data->scale);
    player->punch = load_animator("scripts/animator/punch_player.ani");
    if (player->punch == NULL)
        return (true);
    player->punch->sprite_data->scale = (sfVector2f){6, 6};
    sfSprite_setScale(player->punch->sprite_data->sprite,
    player->punch->sprite_data->scale);
    player->spear = load_animator("scripts/animator/spear_player.ani");
    if (player->spear == NULL)
        return (true);
    player->spear->sprite_data->scale = (sfVector2f){6, 6};
    sfSprite_setScale(player->spear->sprite_data->sprite,
    player->spear->sprite_data->scale);
    player->sword = load_animator("scripts/animator/sword_player.ani");
    if (player->sword == NULL)
        return (true);
    player->sword->sprite_data->scale = (sfVector2f){6, 6};
    sfSprite_setScale(player->sword->sprite_data->sprite,
    player->sword->sprite_data->scale);
    if (init_player_animator_move(player))
        return (true);
    return (false);
}

void init_move_player(player_t *player)
{
    player->pos = (sfVector2f){400, 400};
    player->direction = true;
    player->move_down = false;
    player->move_left = false;
    player->move_right = false;
    player->move_up = false;
    player->player_run = false;
    player->player_walk = false;
    player->weapon = 1;
    player->player_mode = 1;
    player->traveled_distance = 0;
    return;
}

bool init_player(player_t *player)
{
    if (init_player_animator(player))
        return (true);
    if (init_player_clock(player))
        return (true);
    init_move_player(player);
    player->hitbox = (sfIntRect){500, 400, 50, 50}; // pos player x, pos player y, size x, size y
    if (init_stats(&(player->stat)) == 84)
        return (true);
    return (false);
}
