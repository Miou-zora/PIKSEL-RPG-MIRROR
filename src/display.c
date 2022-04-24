/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** display file
*/

#include "my.h"
#include "rpg.h"

void display(scene_t *scene)
{
    sfRenderWindow_drawSprite(scene->window,
    scene->background->sprite, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, scene->hitbox, NULL);
    sfRenderWindow_display(scene->window);
    return;
}