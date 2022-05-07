/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_enemy
*/

#include "struct_var.h"
#include "my.h"

bool init_enemy(game_t *game)
{
    add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    (sfVector2i){CITY, 60});
    add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 600},
    (sfVector2i){CITY, 85});
    add_enemy(BOSS, &(game->enemies_list), (sfVector2f){2000, 600},
    (sfVector2i){CITY, 115});
    add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    (sfVector2i){CITY, 142});
    return (false);
}
