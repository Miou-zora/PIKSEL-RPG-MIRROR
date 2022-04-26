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
    sfRenderWindow_drawRectangleShape(scene->window,
    scene->select_zone->hitbox, NULL);
    if (my_strcmp(scene->zone_name, "settings") == 0) {
        sfRenderWindow_drawRectangleShape(scene->window,
        scene->settings->fill_rectangles[0], NULL);
        sfRenderWindow_drawRectangleShape(scene->window,
        scene->settings->fill_rectangles[1], NULL);
        sfRenderWindow_drawRectangleShape(scene->window,
        scene->settings->fill_rectangles[2], NULL);
    }
    sfRenderWindow_display(scene->window);
    return;
}