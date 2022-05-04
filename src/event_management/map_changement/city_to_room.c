/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** city_to_room
*/

#include "struct_var.h"
#include "my.h"

bool city_to_room(game_t *game)
{
    if (game->player->traveled_distance >= -15
    && game->player->traveled_distance <= 15
    && game->background->scene_background == CITY) {
        game->background->scene_background = ROOM;
        game->player->traveled_distance = 70;
        game->player->pos = (sfVector2f){600, 330};
        return (true);
    }
    return (false);
}