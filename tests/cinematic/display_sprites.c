/*
** EPITECH PROJECT, 2022
** display_sprites
** File description:
** disply_sprites
*/

#include "struct_var.h"

void display_sprite_cinematic(cinematic_t *cinematic)
{
    sfRenderWindow_drawSprite(cinematic->window,
    cinematic->city->sprite, NULL);
    // sfRenderWindow_drawSprite(cinematic->window,
    // cinematic->light->sprite, NULL);
}