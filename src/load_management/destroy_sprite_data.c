/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** destroy_sprite_data
*/

#include "struct_var.h"

void destroy_sprite_data(sprite_data_t *sprite_data)
{
    if (sprite_data) {
        if (sprite_data->sprite) {
            sfSprite_destroy(sprite_data->sprite);
        }
        if (sprite_data->texture) {
            sfTexture_destroy(sprite_data->texture);
        }
        freen((void **)&sprite_data);
    }
}