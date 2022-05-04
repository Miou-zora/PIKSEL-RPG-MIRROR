/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_hitbox
*/

#include "struct_var.h"

void display_hitbox(sfIntRect rect, sfRenderWindow *window)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f pos = {rect.left, rect.top};
    sfVector2f size = {rect.width, rect.height};
    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, sfRed);
    sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
}
