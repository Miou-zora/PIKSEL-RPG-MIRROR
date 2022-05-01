/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_text_zone
*/

#include "rpg.h"

void display_text_zone(sfRenderWindow *window, text_zone_t *text_zone)
{
    sfRenderWindow_drawSprite(window,
    text_zone->text_zone_sprite->sprite, NULL);
    sfRenderWindow_drawText(window, text_zone->text, NULL);
}