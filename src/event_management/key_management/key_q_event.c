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

void move_background_left(game_t *game, int speed)
{
    if (game->background->bedroom->sprite->rect.left > 0
    && game->background->scene_background == ROOM) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, 20);
        game->background->bedroom->sprite->rect.left -= 5 * speed;
        game->player->traveled_distance -= 1 * speed;
        sfSprite_setTextureRect(game->background->bedroom->sprite->sprite ,
        game->background->bedroom->sprite->rect);
    }
    if (game->background->scene_background == CITY
    && game->player->traveled_distance > 0) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, 20);
        game->background->town[0]->sprite->rect.left -= 5 * speed;
        game->background->town[1]->sprite->rect.left -= 10 * speed;
        game->player->traveled_distance -= 1 * speed;
        sfSprite_setTextureRect(game->background->town[0]->sprite->sprite,
        game->background->town[0]->sprite->rect);
        sfSprite_setTextureRect(game->background->town[1]->sprite->sprite,
        game->background->town[1]->sprite->rect);
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