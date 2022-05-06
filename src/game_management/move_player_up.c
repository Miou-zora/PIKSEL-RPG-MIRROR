/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** move_player_up
*/

#include "struct_var.h"
#include "my.h"


void manage_up_lab(game_t *game)
{
    if (game->background->scene_background == LABO
    && game->player->pos.y < 450)
        game->player->move_up = false;
}

void manage_up_forest(game_t *game)
{
    if (game->background->scene_background == FOREST
    && game->player->pos.y < 500)
        game->player->move_up = false;
}

void manage_up_city(game_t *game)
{
    if (game->background->scene_background == CITY
    && game->player->pos.y < 440)
        game->player->move_up = false;
}

void manage_up_room(game_t *game)
{
    if (game->background->scene_background == ROOM
    && game->player->pos.y < 360)
        game->player->move_up = false;
}

void manage_up(game_t *game)
{
    manage_up_room(game);
    manage_up_city(game);
    manage_up_forest(game);
    manage_up_lab(game);
}