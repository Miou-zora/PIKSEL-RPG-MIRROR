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

void create_sprite_player_sword(player_t *player)
{
    player->sword->sprite_data->sprite = sfSprite_create();
    player->sword->sprite_data->texture = sfTexture_createFromFile
    ("assets/player/Stick sword.png", NULL);
    player->sword->sprite_data->scale = (sfVector2f){4, 4};
    player->sword->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->sword->sprite_data->sprite,
    player->sword->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->sword->sprite_data->sprite,
    player->sword->sprite_data->scale);
    sfSprite_setTextureRect(player->sword->sprite_data->sprite,
    player->sword->sprite_data->rect);
    player->sword->number_image = 12;
    player->sword->actual_image = (sfVector2i){0, 0};
    player->sword->nbr_image_xy = (sfVector2i){12, 2};
    player->sword->size_image = (sfVector2f){48, 48};
}

void create_sprite_player_gun(player_t *player)
{
    player->gun->sprite_data->sprite = sfSprite_create();
    player->gun->sprite_data->texture = sfTexture_createFromFile
    ("assets/player/Stick gun.png", NULL);
    player->gun->sprite_data->scale = (sfVector2f){4, 4};
    player->gun->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->gun->sprite_data->sprite,
    player->gun->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->gun->sprite_data->sprite,
    player->gun->sprite_data->scale);
    sfSprite_setTextureRect(player->gun->sprite_data->sprite,
    player->gun->sprite_data->rect);
    player->gun->number_image = 12;
    player->gun->actual_image = (sfVector2i){0, 0};
    player->gun->nbr_image_xy = (sfVector2i){4, 2};
    player->gun->size_image = (sfVector2f){48, 48};
}

void create_sprite_player_spear(player_t *player)
{
    player->spear->sprite_data->sprite = sfSprite_create();
    player->spear->sprite_data->texture = sfTexture_createFromFile
    ("assets/player/Stick spear.png", NULL);
    player->spear->sprite_data->scale = (sfVector2f){4, 4};
    player->spear->sprite_data->rect = (sfIntRect){0, 0, 54, 48};
    sfSprite_setTexture(player->spear->sprite_data->sprite,
    player->spear->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->spear->sprite_data->sprite,
    player->spear->sprite_data->scale);
    sfSprite_setTextureRect(player->spear->sprite_data->sprite,
    player->spear->sprite_data->rect);
    player->spear->number_image = 12;
    player->spear->actual_image = (sfVector2i){0, 0};
    player->spear->nbr_image_xy = (sfVector2i){9, 2};
    player->spear->size_image = (sfVector2f){54, 48};
}

void create_sprite_player_punch(player_t *player)
{
    player->punch->sprite_data->sprite = sfSprite_create();
    player->punch->sprite_data->texture = sfTexture_createFromFile
    ("assets/player/Stick punch.png", NULL);
    player->punch->sprite_data->scale = (sfVector2f){4, 4};
    player->punch->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->punch->sprite_data->sprite,
    player->punch->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->punch->sprite_data->sprite,
    player->punch->sprite_data->scale);
    sfSprite_setTextureRect(player->punch->sprite_data->sprite,
    player->punch->sprite_data->rect);
    player->punch->number_image = 12;
    player->punch->actual_image = (sfVector2i){0, 0};
    player->punch->nbr_image_xy = (sfVector2i){10, 2};
    player->punch->size_image = (sfVector2f){48, 48};
}

void create_sprite_player(player_t *player)
{
    create_sprite_player_iddle(player);
    create_sprite_player_walk(player);
    create_sprite_player_run(player);
    create_sprite_player_punch(player);
    create_sprite_player_sword(player);
    create_sprite_player_gun(player);
    create_sprite_player_spear(player);
}
