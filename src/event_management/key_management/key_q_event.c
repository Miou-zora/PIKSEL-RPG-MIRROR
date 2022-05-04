/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_q_event
*/

#include <stdio.h>
#include "struct_var.h"
#include "my.h"

static void move_forest(game_t *game, int speed)
{
    if (game->background->scene_background == FOREST
    && game->player->traveled_distance > 0) {
        game->background->forest[0]->sprite->rect.left -= 5 * speed;
        game->background->forest[1]->sprite->rect.left -= 10 * speed;
        sfSprite_setTextureRect(game->background->forest[0]->sprite->sprite,
        game->background->forest[0]->sprite->rect);
        sfSprite_setTextureRect(game->background->forest[1]->sprite->sprite,
        game->background->forest[1]->sprite->rect);
    }
}

void move_player_left(game_t *game, int speed)
{
    game->player->pos.x -= 15.f * speed;
    game->player->traveled_distance -= 1;
    if (speed <= 1)
        sfSprite_setPosition(game->player->walk->sprite_data->sprite ,
        game->player->pos);
    else
        sfSprite_setPosition(game->player->run->sprite_data->sprite ,
        game->player->pos);
}

void move_background_left(game_t *game, int speed)
{
    if (game->background->bedroom->sprite->rect.left > 0
    && game->player->pos.x > 500
    && game->player->pos.x < 1000
    && game->background->scene_background == ROOM) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, 20);
        game->background->bedroom->sprite->rect.left -= 5 * speed;
        game->player->traveled_distance -= 1;
        sfSprite_setTextureRect(game->background->bedroom->sprite->sprite ,
        game->background->bedroom->sprite->rect);
        move_player_left(game, 0.2);
    } else if ((game->background->bedroom->sprite->rect.left <= 0
    || game->background->bedroom->sprite->rect.left >= 300)  
    && game->player->pos.x - 15 * speed >= 200
    && game->background->scene_background == ROOM) {
        game->player->traveled_distance -= 1;
        move_player_left(game, speed);
    }
    if (game->background->scene_background == CITY
    && game->player->pos.x > 500
    && game->player->pos.x < 1000
    && game->background->town[0]->sprite->rect.left > 0) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, 20);
        game->background->town[0]->sprite->rect.left -= 5 * speed;
        game->background->town[1]->sprite->rect.left -= 10 * speed;
        game->player->traveled_distance -= 1;
        sfSprite_setTextureRect(game->background->town[0]->sprite->sprite,
        game->background->town[0]->sprite->rect);
        sfSprite_setTextureRect(game->background->town[1]->sprite->sprite,
        game->background->town[1]->sprite->rect);
        move_player_left(game, 0.2);
    } else if (game->background->town[0]->sprite->rect.left <= 0 
    && game->player->pos.x - 16 * speed >= 0
    && game->background->scene_background == CITY) {
        game->player->traveled_distance -= 1;
        move_player_left(game, speed);
    }
    move_forest(game, speed);
}

int manage_key_q(game_t *game)
{
    if (game->event.key.code == sfKeyQ) {
        game->player->move_left = true;
    }
    return (0);
}