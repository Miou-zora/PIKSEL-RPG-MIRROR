/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_one_more_char
*/

#include "struct_var.h"
#include "my.h"

bool room_to_city(game_t *game)
{
    if (game->player->traveled_distance >= 55
    && game->player->traveled_distance <= 65
    && game->background->scene_background == ROOM) {
        game->background->scene_background = CITY;
        game->player->traveled_distance = 0;
        return (true);
    }
    return (false);
}
