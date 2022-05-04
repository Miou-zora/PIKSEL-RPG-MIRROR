/*
** EPITECH PROJECT, 2022
** create_sprite_skip
** File description:
** create_sprite_skip
*/

#include "struct_var.h"

void create_sprite_skip_button(cinematic_t *cinematic)
{
    cinematic->skip_button->pos = (sfVector2f){20, 20};
    sfSprite_setPosition(cinematic->skip_button->sprite,
    cinematic->skip_button->pos);
    cinematic->skip_button->scale = (sfVector2f){4, 4};
    sfSprite_setScale(cinematic->skip_button->sprite,
    cinematic->skip_button->scale);
}
