/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_menu_functions
*/

#include "rpg.h"

int game(void)
{
    my_rpg_player();
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
    return (0);
}

int quit(scene_t *scene)
{
    sfRenderWindow_close(scene->window);
    return (0);
}

int go_to_good_menu(scene_t *scene, settings_t *settings_struct)
{
    if (scene->select_zone->current_pos == 0) {
        return (game());
    }
    if (scene->select_zone->current_pos == 1) {
        if (settings(scene, settings_struct) == 84)
            return (84);
    }
    if (scene->select_zone->current_pos == 2)
        quit(scene);
    return (0);
}