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
    free(scene->select_zone->positions);
    sfRectangleShape_destroy(scene->select_zone->hitbox);
    scene->zone_name = NULL;
    free(scene->select_zone);
    return (0);
}