/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** load_sprite_data
*/

#include "struct_var.h"
#include "my.h"

sprite_data_t *load_sprite_data(char *filename)
{
    sprite_data_t *sprite_data = create_sprite_data();

    if (sprite_data == NULL)
        return (NULL);
    sprite_data->texture = sfTexture_createFromFile(filename, NULL);
    sprite_data->sprite = sfSprite_create();
    if (!sprite_data->texture || !sprite_data->sprite) {
        destroy_sprite_data(&sprite_data);
        return (NULL);
    }
    sfSprite_setTexture(sprite_data->sprite, sprite_data->texture, sfTrue);
    sprite_data->rect = sfSprite_getTextureRect(sprite_data->sprite);
    if (sprite_data->rect.width == 0 || sprite_data->rect.height == 0) {
        destroy_sprite_data(&sprite_data);
        return (NULL);
    }
    return (sprite_data);
}
