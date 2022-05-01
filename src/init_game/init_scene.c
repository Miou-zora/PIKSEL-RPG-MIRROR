/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_scene
*/

#include "rpg.h"

// sfIntRect initialize_hitbox(void)
// {
//     sfIntRect rect;
//     rect.left = 400;
// }

// int initialize_scene(scene_t **scene)
// {
//     (*scene) = malloc(sizeof(scene_t));
//     if ((*scene) == NULL)
//         return (84);
//     if (initialize_window(&((*scene)->window)) == 84)
//         return (84);
//     if (initialize_sprite_data(&((*scene)->background),
//     "assets/menu/menu.png", (sfVector2f){8, 8}, (sfVector2f){0, 0}) == 84)
//         return (84);
//     scene->hitbox = initialize_hitbox();
//     return (0);
// }