/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** free_scene
*/

#include "rpg.h"

int free_scene(scene_t *scene)
{
    sfSprite_destroy(scene->background->sprite);
    sfTexture_destroy(scene->background->texture);
    free(scene->background);
    if (my_strcmp(scene->zone_name, "menu") == 0 ||
    my_strcmp(scene->zone_name, "settings") == 0) {
        free(scene->select_zone->positions);
        sfRectangleShape_destroy(scene->select_zone->hitbox);
        free(scene->select_zone);
    }
    scene->zone_name = NULL;
    return (0);
}