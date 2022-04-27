/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** free_game
*/

#include "rpg.h"

void free_game(scene_t *scene, settings_t *settings, clock_data_t *clock)
{
    free_scene(scene);
    sfRenderWindow_destroy(scene->window);
    sfClock_destroy(clock->clocksfInt64);
    free(scene->settings);
    free(clock);
    free(settings);
    free(scene);
}