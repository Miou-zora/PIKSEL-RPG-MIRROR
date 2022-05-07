/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** room_to_city
*/

#include "struct_var.h"
#include "my.h"

bool room_to_city(game_t *game)
{
    if (game->player->traveled_distance >= 42
    && game->player->traveled_distance <= 55
    && game->background->scene_background == ROOM) {
        game->background->scene_background = CITY;
        game->player->traveled_distance = 0;
        game->player->pos = (sfVector2f){820, 390};
        return (true);
    }
    return (false);
}
