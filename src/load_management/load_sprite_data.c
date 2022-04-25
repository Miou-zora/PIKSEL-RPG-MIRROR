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
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;

    if (sprite_data == NULL)
        return (NULL);
    texture = sfTexture_createFromFile(filename, NULL);
    if (texture == NULL) {
        destroy_sprite_data(&sprite_data);
        return (NULL);
    }
    sprite = sfSprite_create();
    if (sprite == NULL) {
        destroy_sprite_data(&sprite_data);
        return (NULL);
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sprite_data->sprite = sprite;
    sprite_data->texture = texture;
    return (sprite_data);
}