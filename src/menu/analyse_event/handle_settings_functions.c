/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_settings_functions
*/

#include "rpg.h"

void handle_sound(settings_t *settings, sfEvent *event)
{
    if (event->key.code == sfKeyRight || event->key.code == sfKeyD)
        settings->sound = false;
    if (event->key.code == sfKeyLeft || event->key.code == sfKeyQ)
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
    if (event->key.code == sfKeyRight || event->key.code == sfKeyD)
        settings->music = false;
    if (event->key.code == sfKeyLeft || event->key.code == sfKeyQ)
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
    if ((event->key.code == sfKeyRight || event->key.code == sfKeyD)
    && settings->fps < 120)
        settings->fps *= 2;
    if ((event->key.code == sfKeyLeft || event->key.code == sfKeyQ)
    && settings->fps > 30)
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

    free_settings(scene->settings);
    free(scene->settings);
    free_scene(scene);
    initialize_scene(&(new_scene), "menu", 3, false);
    new_scene->window = scene->window;
    *scene = *new_scene;
}