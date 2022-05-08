/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_background_town
*/

#include "my.h"
#include "struct_var.h"

bool init_town_back(town_t **town)
{
    *town = my_calloc(1, sizeof(town_t));

    if (*town == NULL)
        return (true);
    (*town)->sprite = load_sprite_data("assets/background/city.png");
    if ((*town)->sprite == NULL)
        return (true);
    (*town)->sprite->pos = (sfVector2f){0, 0};
    (*town)->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    (*town)->sprite->scale = (sfVector2f){4, 4};
    (*town)->sprite->rect.left += 300;
    (*town)->sprite = set_sprite((*town)->sprite);
    return (false);
}

bool init_town_front(town_t **town)
{
    *town = my_calloc(1, sizeof(town_t));

    if (*town == NULL)
        return (true);
    (*town)->sprite = load_sprite_data("assets/background/light.png");
    if ((*town)->sprite == NULL)
        return (true);
    (*town)->sprite->pos = (sfVector2f){0, 0};
    (*town)->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    (*town)->sprite->scale = (sfVector2f){4, 4};
    (*town)->sprite = set_sprite((*town)->sprite);
    return (false);
}

bool init_town(town_t *town[2])
{
    if (init_town_back(&town[0]))
        return (true);
    if (init_town_front(&town[1]))
        return (true);
    sfTexture_setRepeated(town[0]->sprite->texture, true);
    sfTexture_setRepeated(town[1]->sprite->texture, true);
    return (false);
}

bool init_lose(lose_t **lose)
{
    *lose = malloc(sizeof(lose_t));

    if (*lose == NULL)
        return (true);
    (*lose)->sprite = load_sprite_data("assets/menu/lose.png");
    if ((*lose)->sprite == NULL)
        return (true);
    (*lose)->sprite->pos = (sfVector2f){0, 0};
    (*lose)->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    (*lose)->sprite->scale = (sfVector2f){4, 4};
    (*lose)->sprite = set_sprite((*lose)->sprite);
    return (false);
}