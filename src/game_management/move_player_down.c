/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** move_player_down
*/

#include "struct_var.h"
#include "my.h"

void manage_down_lab(game_t *game)
{
    if (game->background->scene_background == LABO
    && game->player->pos.y > 650)
        game->player->move_down = false;

}

void manage_down_forest(game_t *game)
{
    if (game->background->scene_background == FOREST
    && game->player->pos.y > 700)
        game->player->move_down = false;

}

void manage_down_city(game_t *game)
{
    if (game->background->scene_background == CITY
    && game->player->pos.y > 700)
        game->player->move_down = false;
}

void manage_down_room(game_t *game)
{
    if (game->background->scene_background == ROOM
    && game->player->pos.y > 490) {
        game->player->move_down = false;
    }
}

void manage_down(game_t *game)
{
    manage_down_room(game);
    manage_down_city(game);
    manage_down_forest(game);
    manage_down_lab(game);
}