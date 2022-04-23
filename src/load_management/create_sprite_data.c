/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_sprite_data
*/

#include "struct_var.h"
#include <stdlib.h>

sprite_data_t *create_sprite_data(void)
{
    sprite_data_t *sprite_data = malloc(sizeof(sprite_data_t));

    if (sprite_data == NULL)
        return (NULL);
    sprite_data->sprite = NULL;
    sprite_data->texture = NULL;
    sprite_data->pos = (sfVector2f){0, 0};
    sprite_data->scale = (sfVector2f){0, 0};
    return (sprite_data);
}