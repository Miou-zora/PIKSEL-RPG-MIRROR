/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_sprite_data
*/

#include "struct_var.h"
#include "my.h"
#include <stdlib.h>

sprite_data_t *create_sprite_data(void)
{
    sprite_data_t *sprite_data = malloc(sizeof(*sprite_data));
    if (sprite_data) {
        sprite_data->sprite = NULL;
        sprite_data->texture = NULL;
        sprite_data->pos = (sfVector2f){NOT_SET, NOT_SET};
        sprite_data->scale = (sfVector2f){1, 1};
        sprite_data->rect = (sfIntRect){NOT_SET, NOT_SET, NOT_SET, NOT_SET};
    }
    return (sprite_data);
}
