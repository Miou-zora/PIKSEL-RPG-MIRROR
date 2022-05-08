/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_healthbar
*/

#include "struct_var.h"

void display_healthbar(enemy_t *enemy, sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture;

    if (!enemy || !window || !(enemy->healthbar) || !sprite ||
    !(enemy->actual_animator))
        return;
    texture = sfTexture_create(enemy->healthbar->width,
    enemy->healthbar->height);
    sfTexture_updateFromPixels(texture, enemy->healthbar->pixels,
    enemy->healthbar->width, enemy->healthbar->height, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){enemy->pos.x, enemy->pos.y -
    25});
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
