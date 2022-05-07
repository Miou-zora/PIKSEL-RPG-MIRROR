/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_background_forest
*/

#include "my.h"
#include "struct_var.h"

bool init_forest_back(forest_t **forest)
{
    *forest = my_calloc(1, sizeof(forest_t));

    if (*forest == NULL)
        return (true);
    (*forest)->sprite = load_sprite_data("assets/background/forest_back.png");
    if ((*forest)->sprite == NULL)
        return (true);
    (*forest)->sprite->pos = (sfVector2f){0, 0};
    (*forest)->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    (*forest)->sprite->scale = (sfVector2f){4, 4};
    (*forest)->sprite = set_sprite((*forest)->sprite);
    return (false);
}

bool init_forest_front(forest_t **forest)
{
    *forest = my_calloc(1, sizeof(forest_t));

    if (*forest == NULL)
        return (true);
    (*forest)->sprite = load_sprite_data("assets/background/forest_front.png");
    if ((*forest)->sprite == NULL)
        return (true);
    (*forest)->sprite->pos = (sfVector2f){0, 0};
    (*forest)->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    (*forest)->sprite->scale = (sfVector2f){4, 4};
    (*forest)->sprite = set_sprite((*forest)->sprite);
    return (false);
}

bool init_forest(forest_t *forest[2])
{
    if (init_forest_back(&forest[0]))
        return (true);
    if (init_forest_front(&forest[1]))
        return (true);
    sfTexture_setRepeated(forest[0]->sprite->texture, true);
    sfTexture_setRepeated(forest[1]->sprite->texture, true);
    return (false);
}