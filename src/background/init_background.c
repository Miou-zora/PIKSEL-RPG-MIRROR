/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "struct_var.h"

sprite_data_t *set_sprite(sprite_data_t *sprite)
{
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_scale(sprite->sprite, sprite->scale);
    return (sprite);
}

bool init_room(bedroom_t **bedroom)
{
    *bedroom = malloc(sizeof(bedroom_t));

    if (*bedroom == NULL)
        return (true);
    (*bedroom)->sprite = load_sprite_data("assets/background/appart.png");
    if ((*bedroom)->sprite == NULL)
        return (true);
    (*bedroom)->sprite->pos = (sfVector2f){0, 0};
    (*bedroom)->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    (*bedroom)->sprite->scale = (sfVector2f){4, 4};
    (*bedroom)->sprite = set_sprite((*bedroom)->sprite);
    return (false);
}

bool init_laboratory(laboratory_t **laboratory)
{
    *laboratory = malloc(sizeof(laboratory_t));

    if (*laboratory == NULL)
        return (true);
    (*laboratory)->sprite = load_sprite_data("assets/background/Labo.png");
    if ((*laboratory)->sprite == NULL)
        return (true);
    (*laboratory)->sprite->pos = (sfVector2f){0, 0};
    (*laboratory)->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    (*laboratory)->sprite->scale = (sfVector2f){4, 4};
    (*laboratory)->sprite = set_sprite((*laboratory)->sprite);
    return (false);
}

bool init_back(background_t *background)
{
    background->scene_background = MENU;
    if (background == NULL)
        return (true);
    if (init_room(&(background->bedroom)))
        return (true);
    if (init_laboratory(&(background->laboratory)))
        return (true);
    return (false);
}