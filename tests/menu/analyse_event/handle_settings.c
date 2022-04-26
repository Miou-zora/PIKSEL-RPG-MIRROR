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

void modify_display_of_settings(scene_t *scene)
{
    if (scene->settings->sound == true) {
        change_position_and_size(scene, 0, 0);
    } else {
        change_position_and_size(scene, 0, 1);
    }
    if (scene->settings->music == true) {
        change_position_and_size(scene, 1, 2);
    } else {
        change_position_and_size(scene, 1, 3);
    }
    if (scene->settings->fps == 30) {
        change_position_and_size(scene, 2, 4);
    } else if (scene->settings->fps == 60) {
        change_position_and_size(scene, 2, 5);
    } else {
        change_position_and_size(scene, 2, 6);
    }
}

void handle_sound(scene_t *scene, sfEvent *event)
{
    if (event->key.code == sfKeyRight)
        scene->settings->sound = false;
    if (event->key.code == sfKeyLeft)
        scene->settings->sound = true;
    if (event->key.code == sfKeySpace || event->key.code == sfKeyEnter) {
        if (scene->settings->sound == false)
            scene->settings->sound = true;
        else
            scene->settings->sound = false;
    }
}

void handle_music(scene_t *scene, sfEvent *event)
{
    if (event->key.code == sfKeyRight)
        scene->settings->music = false;
    if (event->key.code == sfKeyLeft)
        scene->settings->music = true;
    if (event->key.code == sfKeySpace || event->key.code == sfKeyEnter) {
        if (scene->settings->music == false)
            scene->settings->music = true;
        else
            scene->settings->music = false;
    }
}

void handle_fps(scene_t *scene, sfEvent *event)
{
    if (event->key.code == sfKeyRight && scene->settings->fps < 120)
        scene->settings->fps *= 2;
    if (event->key.code == sfKeyLeft && scene->settings->fps > 30)
        scene->settings->fps /= 2;
    if (event->key.code == sfKeySpace || event->key.code == sfKeyEnter) {
        if (scene->settings->fps < 120)
            scene->settings->fps *= 2;
        else
            scene->settings->fps = 30;
    }
}

void handle_settings(scene_t *scene, sfEvent *event)
{
    void(*settings[3])(scene_t *scene, sfEvent *event) =
    {handle_sound, handle_music, handle_fps};
    settings[scene->select_zone->current_pos](scene, event);
    modify_display_of_settings(scene);
}