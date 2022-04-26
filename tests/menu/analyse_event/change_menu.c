/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** change_menu
*/

#include "rpg.h"

int handle_keyboard_inputs(sfEvent *event,
scene_t *scene, settings_t **settings_struct)
{
    if ((event->key.code == sfKeyDown || event->key.code == sfKeyS) &&
    scene->select_zone->current_pos != scene->select_zone->nb_of_poses - 1) {
        scene->select_zone->current_pos++;
        sfRectangleShape_setPosition(scene->select_zone->hitbox,
        scene->select_zone->positions[scene->select_zone->current_pos]);
    }
    if ((event->key.code == sfKeyUp || event->key.code == sfKeyZ) &&
    scene->select_zone->current_pos != 0) {
        scene->select_zone->current_pos--;
        sfRectangleShape_setPosition(scene->select_zone->hitbox,
        scene->select_zone->positions[scene->select_zone->current_pos]);
    }
    if ((event->key.code == sfKeyEnter || event->key.code == sfKeySpace)
    && my_strcmp(scene->zone_name, "menu")
    == 0) {
        if (go_to_good_menu(scene, (*settings_struct)) == 84)
            return (84);
    }
    return (0);
}

int change_menu(sfEvent *event, scene_t *scene, settings_t **settings_struct)
{
    if (handle_keyboard_inputs(event, scene, settings_struct) == 84)
        return (84);
    if (my_strcmp(scene->zone_name, "settings") == 0) {
        handle_settings(&scene, event, (*settings_struct));
    }
    return (0);
}