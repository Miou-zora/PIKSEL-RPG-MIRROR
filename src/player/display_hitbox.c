/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_hitbox
*/

#include "struct_var.h"
#include "my.h"

void display_hitbox(sfIntRect rect, sfRenderWindow *window, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f pos = {rect.left, rect.top};
    sfVector2f size = {rect.width, rect.height};

    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRectangleShape_setOutlineColor(rectangle, color);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
}
