/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** display file
*/

#include "struct_var.h"
#include "my.h"

//UTILISER L'AUTRE DISPLAY ET UPDATE

void display_menu(scene_t *scene, dialogues_t *dialogue)
{
    sfRenderWindow_drawSprite(scene->window,
    scene->background->sprite, NULL);
    if (my_strcmp(scene->zone_name, "menu") == 0
    || my_strcmp(scene->zone_name, "settings") == 0) {
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
    }
    if (my_strcmp(scene->zone_name, "game") == 0) {
        display_text_zone(scene->window, dialogue->text_zone);
    }
    sfRenderWindow_display(scene->window);
    return;
}