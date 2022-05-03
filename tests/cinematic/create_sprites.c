/*
** EPITECH PROJECT, 2022
** create_sprites
** File description:
** create_sprites
*/

#include "struct_var.h"
#include "my.h"

void create_sprite_cine_player(cinematic_t *cinematic)
{
    cinematic->anim_player_walk->sprite_data->pos = (sfVector2f){1920, 500};
    sfSprite_setPosition(cinematic->anim_player_walk->sprite_data->sprite,
    cinematic->anim_player_walk->sprite_data->pos);
    cinematic->anim_player_walk->sprite_data->scale = (sfVector2f){4, 4};
    cinematic->anim_player_walk->sprite_data->rect = (sfIntRect){0, 48, 48, 48};
    sfSprite_setScale(cinematic->anim_player_walk->sprite_data->sprite,
    cinematic->anim_player_walk->sprite_data->scale);
    sfSprite_setTextureRect(cinematic->anim_player_walk->sprite_data->sprite,
    cinematic->anim_player_walk->sprite_data->rect);
}

void create_sprite_cine_enemy(cinematic_t *cinematic)
{
    cinematic->anim_enemy_run->sprite_data->pos = (sfVector2f){0, 515};
    sfSprite_setPosition(cinematic->anim_enemy_run->sprite_data->sprite,
    cinematic->anim_enemy_run->sprite_data->pos);
    cinematic->anim_enemy_run->sprite_data->scale = (sfVector2f){4, 4};
    cinematic->anim_enemy_run->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setScale(cinematic->anim_enemy_run->sprite_data->sprite,
    cinematic->anim_enemy_run->sprite_data->scale);
    sfSprite_setTextureRect(cinematic->anim_enemy_run->sprite_data->sprite,
    cinematic->anim_enemy_run->sprite_data->rect);
}

void create_sprite_cine_city(cinematic_t *cinematic)
{

    cinematic->city->scale = (sfVector2f){4, 4};
    sfSprite_setScale(cinematic->city->sprite,
    cinematic->city->scale);
}

void create_sprite_cine_light(cinematic_t *cinematic)
{
    cinematic->light->scale = (sfVector2f){4, 4};
    sfSprite_setScale(cinematic->light->sprite,
    cinematic->light->scale);
}

void create_sprites_cinematic(cinematic_t *cinematic)
{
    create_sprite_cine_player(cinematic);
    create_sprite_cine_enemy(cinematic);
    create_sprite_cine_city(cinematic);
    create_sprite_cine_light(cinematic);
}