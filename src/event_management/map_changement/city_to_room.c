/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_one_more_char
*/

#include "struct_var.h"
#include "my.h"

bool city_to_room(game_t *game)
{
    if (game->player->traveled_distance >= 0
    && game->player->traveled_distance <= 20
    && game->background->scene_background == CITY) {
        game->background->scene_background = ROOM;
        game->player->traveled_distance = 55;
        return (true);
    }
    return (false);
}