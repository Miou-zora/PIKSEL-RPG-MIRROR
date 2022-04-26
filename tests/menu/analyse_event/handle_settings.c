/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_settings
*/

#include "rpg.h"

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

void handle_sound(settings_t *settings, sfEvent *event)
{
    if (event->key.code == sfKeyRight)
        settings->sound = false;
    if (event->key.code == sfKeyLeft)
        settings->sound = true;
    if (event->key.code == sfKeySpace || event->key.code == sfKeyEnter) {
        if (settings->sound == false)
            settings->sound = true;
        else
            settings->sound = false;
    }
}

void handle_music(settings_t *settings, sfEvent *event)
{
    if (event->key.code == sfKeyRight)
        settings->music = false;
    if (event->key.code == sfKeyLeft)
        settings->music = true;
    if (event->key.code == sfKeySpace || event->key.code == sfKeyEnter) {
        if (settings->music == false)
            settings->music = true;
        else
            settings->music = false;
    }
}

void handle_fps(settings_t *settings, sfEvent *event)
{
    if (event->key.code == sfKeyRight && settings->fps < 120)
        settings->fps *= 2;
    if (event->key.code == sfKeyLeft && settings->fps > 30)
        settings->fps /= 2;
    if (event->key.code == sfKeySpace || event->key.code == sfKeyEnter) {
        if (settings->fps < 120)
            settings->fps *= 2;
        else
            settings->fps = 30;
    }
}

void handle_quit(scene_t *scene)
{
    scene_t *new_scene = NULL;

    free_scene(scene);
    initialize_scene(&(new_scene), "menu", 3, false);
    new_scene->window = scene->window;
    *scene = *new_scene;
}

void handle_settings(scene_t **scene, sfEvent *event, settings_t *settings_struct)
{
    void(*settings[3])(settings_t *settings,
    sfEvent *event) =
    {handle_sound, handle_music, handle_fps};

    if (event->key.code == sfKeyEscape) {
        my_putstr("coucou");
        handle_quit((*scene));
    }
    if ((*scene)->select_zone->current_pos == 3)
        sfRectangleShape_setSize((*scene)->select_zone->hitbox,
        (sfVector2f){190, 170});
    else
        sfRectangleShape_setSize((*scene)->select_zone->hitbox,
        (sfVector2f){1220, 135});
    if ((*scene)->select_zone->current_pos <
    (*scene)->select_zone->nb_of_poses - 1) {
        settings[(*scene)->select_zone->current_pos](settings_struct,
        event);
    } else if (event->key.code == sfKeyEnter ||
    event->key.code == sfKeySpace) {
        handle_quit((*scene));
    }
    if (my_strcmp((*scene)->zone_name, "settings") == 0)
            modify_display_of_settings(settings_struct, (*scene));
}