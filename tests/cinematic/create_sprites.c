/*
** EPITECH PROJECT, 2022
** create_sprites
** File description:
** create_sprites
*/

#include "struct_var.h"

void create_sprite_cine_player(cinematic_t *cinematic)
{
    cinematic->city->sprite = sfSprite_create();
    cinematic->city->texture = sfTexture_createFromFile(
    "assets/background/city.png", NULL);
    cinematic->city->scale = (sfVector2f){4, 4};
    cinematic->city->rect = (sfIntRect){0, 48, 48, 48};
    sfSprite_setTexture(cinematic->city->sprite,
    cinematic->city->texture, sfTrue);
    sfSprite_setScale(cinematic->city->sprite,
    cinematic->city->scale);
    sfSprite_setTextureRect(cinematic->city->sprite,
    cinematic->city->rect);
}

void create_sprite_cine_enemy(cinematic_t *cinematic)
{
    cinematic->city->sprite = sfSprite_create();
    cinematic->city->texture = sfTexture_createFromFile(
    "assets/background/city.png", NULL);
    cinematic->city->scale = (sfVector2f){4, 4};
    cinematic->city->rect = (sfIntRect){0, 48, 48, 48};
    sfSprite_setTexture(cinematic->city->sprite,
    cinematic->city->texture, sfTrue);
    sfSprite_setScale(cinematic->city->sprite,
    cinematic->city->scale);
    sfSprite_setTextureRect(cinematic->city->sprite,
    cinematic->city->rect);
}

void create_sprite_cine_city(cinematic_t *cinematic)
{
    cinematic->city->sprite = sfSprite_create();
    cinematic->city->texture = sfTexture_createFromFile(
    "assets/background/city.png", NULL);
    cinematic->city->scale = (sfVector2f){4, 4};
    cinematic->city->rect = (sfIntRect){0, 48, 48, 48};
    sfSprite_setTexture(cinematic->city->sprite,
    cinematic->city->texture, sfTrue);
    sfSprite_setScale(cinematic->city->sprite,
    cinematic->city->scale);
    sfSprite_setTextureRect(cinematic->city->sprite,
    cinematic->city->rect);
}

void create_sprite_cine_light(cinematic_t *cinematic)
{
    cinematic->light->sprite = sfSprite_create();
    cinematic->light->texture = sfTexture_createFromFile(
    "assets/background/Lampadaire.png", NULL);
    cinematic->light->scale = (sfVector2f){4, 4};
    cinematic->light->rect = (sfIntRect){0, 48, 48, 48};
    sfSprite_setTexture(cinematic->light->sprite,
    cinematic->light->texture, sfTrue);
    sfSprite_setScale(cinematic->light->sprite,
    cinematic->light->scale);
    sfSprite_setTextureRect(cinematic->light->sprite,
    cinematic->light->rect);
}

void create_sprites_cinematic(cinematic_t *cinematic)
{
    create_sprite_cine_player(cinematic);
    create_sprite_cine_enemy(cinematic);
    create_sprite__cine_city(cinematic);
    create_sprite_cine_lighr(cinematic);
}