/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** move_player_with_back
*/

#include "struct_var.h"

void move_player_right(game_t *game, int speed)
{
    game->player->pos.x += 15.f * speed;
    if (speed <= 1)
        sfSprite_setPosition(game->player->walk->sprite_data->sprite ,
        game->player->pos);
    else
        sfSprite_setPosition(game->player->run->sprite_data->sprite ,
        game->player->pos);
}

void move_player_left(game_t *game, int speed)
{
    game->player->pos.x -= 15.f * speed;
    if (speed <= 1)
        sfSprite_setPosition(game->player->walk->sprite_data->sprite ,
        game->player->pos);
    else
        sfSprite_setPosition(game->player->run->sprite_data->sprite ,
        game->player->pos);
}
