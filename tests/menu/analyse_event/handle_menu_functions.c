/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_menu_functions
*/

#include "rpg.h"

int game(scene_t *scene, text_zone_t **text_zone)
{
    scene_t *new_scene = NULL;

    if (free_scene(scene) == 84)
        return (84);
    if (initialize_game(&(new_scene), scene) == 84)
        return (84);
    *scene = *new_scene;
    create_text_zone(text_zone, "salut mec comment ca va timothée coucou coucou regarde je peux changer de ligne");
    if (initialize_clock(&((*text_zone)->text_clock)) == 84)
        return (84);
    return (0);
}

int settings(scene_t *scene, settings_t *settings_struct)
{
    scene_t *new_scene = NULL;

    if (free_scene(scene) == 84)
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

int go_to_good_menu(scene_t *scene,
settings_t *settings_struct, text_zone_t **text_zone)
{
    if (scene->select_zone->current_pos == 0) {
        return (game(scene, text_zone));
    }
    if (scene->select_zone->current_pos == 1) {
        if (settings(scene, settings_struct) == 84)
            return (84);
    }
    if (scene->select_zone->current_pos == 2)
        quit(scene);
    return (0);
}