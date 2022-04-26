/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_sprite
*/

#include "rpg.h"

int initialize_sprite_data(sprite_data_t **sprite_data, char *path_to_image,
sfVector2f scale, sfVector2f position)
{
    (*sprite_data) = my_calloc(1, sizeof(*(*sprite_data)));
    (*sprite_data)->sprite = sfSprite_create();
    if ((*sprite_data)->sprite == NULL)
        return (84);
    (*sprite_data)->texture = sfTexture_createFromFile(path_to_image, NULL);
    if ((*sprite_data)->texture == NULL)
        return (84);
    (*sprite_data)->position = position;
    (*sprite_data)->scale = scale;
    sfSprite_setScale((*sprite_data)->sprite, (*sprite_data)->scale);
    sfSprite_setPosition((*sprite_data)->sprite, (*sprite_data)->position);
    sfSprite_setTexture((*sprite_data)->sprite, (*sprite_data)->texture, sfFalse);
    return (0);
}