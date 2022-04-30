/*
** EPITECH PROJECT, 2022
** create_sprites_player
** File description:
** create_sprites_player
*/

#include "struct_var.h"

void create_sprite_player_walk(player_t *player)
{
    player->walk->sprite_data->sprite = sfSprite_create();
    player->walk->sprite_data->texture = sfTexture_createFromFile(
        "assets/player/Stick walk.png", NULL);
    player->walk->sprite_data->scale = (sfVector2f){4, 4};
    player->walk->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->walk->sprite_data->sprite,
    player->walk->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->walk->sprite_data->sprite,
    player->walk->sprite_data->scale);
    sfSprite_setTextureRect(player->walk->sprite_data->sprite,
    player->walk->sprite_data->rect);
    player->walk->number_image = 12;
    player->walk->actual_image = (sfVector2i){0, 0};
    player->walk->nbr_image_xy = (sfVector2i){6, 2};
    player->walk->size_image = (sfVector2f){48, 48};
}

void create_sprite_player_run(player_t *player)
{
    player->run->sprite_data->sprite = sfSprite_create();
    player->run->sprite_data->texture = sfTexture_createFromFile
    ("assets/player/Stick run.png", NULL);
    player->run->sprite_data->scale = (sfVector2f){4, 4};
    player->run->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->run->sprite_data->sprite,
    player->run->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->run->sprite_data->sprite,
    player->run->sprite_data->scale);
    sfSprite_setTextureRect(player->run->sprite_data->sprite,
    player->run->sprite_data->rect);
    player->run->number_image = 12;
    player->run->actual_image = (sfVector2i){0, 0};
    player->run->nbr_image_xy = (sfVector2i){6, 2};
    player->run->size_image = (sfVector2f){48, 48};
}

void create_sprite_player_iddle(player_t *player)
{
    player->iddle->sprite_data->sprite = sfSprite_create();
    player->iddle->sprite_data->texture = sfTexture_createFromFile
    ("assets/player/Stick iddle.png", NULL);
    player->iddle->sprite_data->scale = (sfVector2f){4, 4};
    player->iddle->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->scale);
    sfSprite_setTextureRect(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->rect);
    player->iddle->number_image = 12;
    player->iddle->actual_image = (sfVector2i){0, 0};
    player->iddle->nbr_image_xy = (sfVector2i){6, 2};
    player->iddle->size_image = (sfVector2f){48, 48};
}

void create_sprite_player(player_t *player)
{
    create_sprite_player_iddle(player);
    create_sprite_player_walk(player);
    create_sprite_player_run(player);
}
