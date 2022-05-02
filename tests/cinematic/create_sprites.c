/*
** EPITECH PROJECT, 2022
** create_sprites
** File description:
** create_sprites
*/

#include "struct_var.h"

void create_sprite_cine_player(cinematic_t *cinematic)
{
    cinematic->player_walk->sprite_data->sprite = sfSprite_create();
    cinematic->player_walk->sprite_data->texture = sfTexture_createFromFile(
    "assets/player/Stick walk.png", NULL);
    cinematic->player_walk->sprite_data->scale = (sfVector2f){4, 4};
    cinematic->player_walk->sprite_data->rect = (sfIntRect){0, 48, 48, 48};
    sfSprite_setTexture(cinematic->player_walk->sprite_data->sprite,
    cinematic->player_walk->sprite_data->texture, sfTrue);
    sfSprite_setScale(cinematic->player_walk->sprite_data->sprite,
    cinematic->player_walk->sprite_data->scale);
    sfSprite_setTextureRect(cinematic->player_walk->sprite_data->sprite,
    cinematic->player_walk->sprite_data->rect);
}

void create_sprite_cine_enemy(cinematic_t *cinematic)
{
    cinematic->enemy_run->sprite_data->sprite = sfSprite_create();
    cinematic->enemy_run->sprite_data->texture = sfTexture_createFromFile(
    "assets/player/Stick run.png", NULL);
    cinematic->enemy_run->sprite_data->pos = (sfVector2f){100, 0};
    sfSprite_setPosition(cinematic->enemy_run->sprite_data->sprite,
    cinematic->enemy_run->sprite_data->pos);
    cinematic->enemy_run->sprite_data->scale = (sfVector2f){4, 4};
    cinematic->enemy_run->sprite_data->rect = (sfIntRect){0, 48, 48, 48};
    sfSprite_setTexture(cinematic->enemy_run->sprite_data->sprite,
    cinematic->enemy_run->sprite_data->texture, sfTrue);
    sfSprite_setScale(cinematic->enemy_run->sprite_data->sprite,
    cinematic->enemy_run->sprite_data->scale);
    sfSprite_setTextureRect(cinematic->enemy_run->sprite_data->sprite,
    cinematic->enemy_run->sprite_data->rect);
}

void create_sprite_cine_city(cinematic_t *cinematic)
{
    cinematic->city->sprite = sfSprite_create();
    cinematic->city->texture = sfTexture_createFromFile(
    "assets/background/city.png", NULL);
    cinematic->city->scale = (sfVector2f){4, 4};
    sfSprite_setTexture(cinematic->city->sprite,
    cinematic->city->texture, sfTrue);
    sfSprite_setScale(cinematic->city->sprite,
    cinematic->city->scale);
}

void create_sprite_cine_light(cinematic_t *cinematic)
{
    cinematic->light->sprite = sfSprite_create();
    cinematic->light->texture = sfTexture_createFromFile(
    "assets/background/Lampadaire.png", NULL);
    cinematic->light->scale = (sfVector2f){4, 4};
    sfSprite_setTexture(cinematic->light->sprite,
    cinematic->light->texture, sfTrue);
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