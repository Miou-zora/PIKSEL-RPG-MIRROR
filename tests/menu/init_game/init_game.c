/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_game
*/

#include "rpg.h"

int initialize_game(scene_t **game_scene, scene_t *old_scene)
{
    sfRenderWindow_clear(old_scene->window, sfBlack);
    (*game_scene) = malloc(sizeof(scene_t));

    if ((*game_scene) == NULL)
        return (84);
    if (initialize_sprite_data(&((*game_scene)->background),
    "assets/menu/menu.png", (sfVector2f){8, 8}, (sfVector2f){0, 0}) == 84)
        return (84);
    (*game_scene)->window = old_scene->window;
    (*game_scene)->zone_name = "game";
    return (0);
}