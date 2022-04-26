/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** change_menu
*/

#include "rpg.h"

int game(scene_t *scene)
{
    sfRenderWindow_display(scene->window);
    my_putstr("game\n");
    return (0);
}

int settings(scene_t *scene, settings_t *settings_struct)
{
    scene_t *new_scene = NULL;

    if(free_scene(scene) == 84)
        return (84);
    if (initialize_settings(&(new_scene), scene) == 84)
        return (84);
    *scene = *new_scene;
    if (scene == NULL)
        return (84);
    if (settings_struct->sound == false)
        settings_struct->sound = true;
    else
        settings_struct->sound = false;
    my_putstr("settings\n");
    return (0);
}

int quit(scene_t *scene)
{
    sfRenderWindow_close(scene->window);
    return (0);
}

int go_to_good_menu(scene_t *scene, settings_t *settings_struct)
{
    if (scene->select_zone->current_pos == 0)
        game(scene);
    if (scene->select_zone->current_pos == 1)
        if (settings(scene, settings_struct) == 84)
            return (84);
    if (scene->select_zone->current_pos == 2)
        quit(scene);
    return (0);
}

int handle_keyboard_inputs(sfEvent *event, scene_t *scene, settings_t **settings_struct)
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
    if (event->key.code == sfKeyEnter && my_strcmp(scene->zone_name, "menu")
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