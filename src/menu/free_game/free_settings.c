/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** free_settings
*/

#include "rpg.h"

void free_settings(settings_infos_t *settings)
{
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_destroy(settings->fill_rectangles[i]);
    }
}