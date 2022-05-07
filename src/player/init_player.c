/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_player
*/

#include "my.h"
#include "struct_var.h"

bool init_player_animator_gun_and_punch(player_t *player)
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
    return (false);
}

bool init_player_animator(player_t *player)
{
    if (init_player_animator_gun_and_punch(player))
        return (true);
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
    player->hitbox = (sfIntRect){player->pos.x, player->pos.y + 100, 100, 20};
    player->hitbox_color = sfRed;
    if (init_stats(&(player->stat)) == 84)
        return (true);
    return (false);
}
