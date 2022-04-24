/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_scene
*/

#include "rpg.h"

sfRectangleShape *initialize_hitbox(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){380, 295});
    sfRectangleShape_setOutlineColor(rect, sfGreen);
    sfRectangleShape_setOutlineThickness(rect, 4);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setSize(rect, (sfVector2f){1200, 135});
    return (rect);
}

int initialize_scene(scene_t **scene)
{
    (*scene) = malloc(sizeof(scene_t));
    if ((*scene) == NULL)
        return (84);
    if (initialize_window(&((*scene)->window)) == 84)
        return (84);
    if (initialize_sprite_data(&((*scene)->background),
    "assets/menu/menu.png", (sfVector2f){8, 8}, (sfVector2f){0, 0}) == 84)
        return (84);
    (*scene)->hitbox = initialize_hitbox();
    return (0);
}