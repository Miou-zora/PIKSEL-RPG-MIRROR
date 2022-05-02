/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_settings
*/

#include "rpg.h"
#include "my.h"

void change_position_and_size(scene_t *scene,
int which_rect, int which_pos_and_size)
{
    sfRectangleShape_setPosition(scene->settings->fill_rectangles[which_rect],
    scene->settings->rectangles_positions[which_pos_and_size]);
    sfRectangleShape_setSize(scene->settings->fill_rectangles[which_rect],
    scene->settings->rectangles_sizes[which_pos_and_size]);
}

void modify_display_of_settings(settings_t *settings, scene_t *scene)
{
    if (settings->sound == true) {
        change_position_and_size(scene, 0, 0);
    } else {
        change_position_and_size(scene, 0, 1);
    }
    if (settings->music == true) {
        change_position_and_size(scene, 1, 2);
    } else {
        change_position_and_size(scene, 1, 3);
    }
    if (settings->fps == 30) {
        change_position_and_size(scene, 2, 4);
    } else if (settings->fps == 60) {
        change_position_and_size(scene, 2, 5);
    } else {
        change_position_and_size(scene, 2, 6);
    }
}

void call_settings_functions(scene_t *scene,
settings_t *settings_struct, sfEvent *event)
{
    void(*settings[3])(settings_t *settings,
    sfEvent *event) =
    {handle_sound, handle_music, handle_fps};

    if (scene->select_zone->current_pos <
    scene->select_zone->nb_of_poses - 1) {
        settings[scene->select_zone->current_pos](settings_struct,
        event);
    } else if (event->key.code == sfKeyEnter ||
    event->key.code == sfKeySpace) {
        handle_quit(scene);
    }
}

void handle_settings(scene_t **scene,
sfEvent *event, settings_t *settings_struct)
{
    if (event->key.code == sfKeyEscape) {
        handle_quit((*scene));
    }
    if ((*scene)->select_zone->current_pos == 3)
        sfRectangleShape_setSize((*scene)->select_zone->hitbox,
        (sfVector2f){190, 170});
    else
        sfRectangleShape_setSize((*scene)->select_zone->hitbox,
        (sfVector2f){1220, 135});
    call_settings_functions((*scene), settings_struct, event);
    if (my_strcmp((*scene)->zone_name, "settings") == 0)
        modify_display_of_settings(settings_struct, (*scene));
}