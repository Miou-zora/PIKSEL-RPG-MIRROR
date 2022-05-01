/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** free_game
*/

#include "rpg.h"

void free_game(scene_t *scene, settings_t *settings,
clock_data_t *clock, dialogues_t *dialogue)
{
    if (my_strcmp(scene->zone_name, "game") == 0) {
        free_dialogue(&dialogue);
    }
    char *zone_name = malloc(sizeof(char) * (my_strlen(scene->zone_name) + 1));
    my_strcpy(zone_name, scene->zone_name);
    free_scene(scene);
    sfRenderWindow_destroy(scene->window);
    sfClock_destroy(clock->clocksfInt64);
    if (my_strcmp(zone_name, "menu") == 0 ||
    my_strcmp(zone_name, "settings") == 0)
        free(scene->settings);
    free(zone_name);
    free(clock);
    free(settings);
    free(scene);
}