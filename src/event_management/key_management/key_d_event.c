/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_d_event
*/

#include "struct_var.h"
#include "my.h"
#include <stdio.h>

static void move_forest(game_t *game, int speed)
{
    if (game->background->scene_background == FOREST) {
        game->background->forest[0]->sprite->rect.left += 5 * speed;
        game->background->forest[1]->sprite->rect.left += 10 * speed;
        game->player->traveled_distance += 1;
        sfSprite_setTextureRect(game->background->forest[0]->sprite->sprite,
        game->background->forest[0]->sprite->rect);
        sfSprite_setTextureRect(game->background->forest[1]->sprite->sprite,
        game->background->forest[1]->sprite->rect);
    }
}

void move_player_right(game_t *game, int speed)
{
    game->player->pos.x += 15.f * speed;
    game->player->traveled_distance += 1;
    if (speed <= 1)
        sfSprite_setPosition(game->player->walk->sprite_data->sprite ,
        game->player->pos);
    else
        sfSprite_setPosition(game->player->run->sprite_data->sprite ,
        game->player->pos);
}
void move_background_right(game_t *game, int speed)
{
    if (game->background->bedroom->sprite->rect.left < 300
    && game->player->pos.x > 500
    && game->player->pos.x < 1000
    && game->background->scene_background == ROOM) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, -20);
        game->background->bedroom->sprite->rect.left += 5 * speed;
        game->player->traveled_distance += 1;
        sfSprite_setTextureRect(game->background->bedroom->sprite->sprite ,
        game->background->bedroom->sprite->rect);
        move_player_right(game, 0.2);
    } else if ((game->background->bedroom->sprite->rect.left <= 0
    || game->background->bedroom->sprite->rect.left >= 300)  
    && game->player->pos.x - 16 * speed <= 1600
    && game->background->scene_background == ROOM) {
        game->player->traveled_distance += 1;
        move_player_right(game, speed);
    }
    if (game->background->scene_background == CITY
    && game->player->pos.x > 500
    && game->player->pos.x < 1000) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, -20);
        game->background->town[0]->sprite->rect.left += 5 * speed;
        game->background->town[1]->sprite->rect.left += 10 * speed;
        game->player->traveled_distance += 1;
        sfSprite_setTextureRect(game->background->town[0]->sprite->sprite,
        game->background->town[0]->sprite->rect);
        sfSprite_setTextureRect(game->background->town[1]->sprite->sprite,
        game->background->town[1]->sprite->rect);
        move_player_right(game, 0.2);
    } else if (game->background->town[0]->sprite->rect.left <= 0  
    && game->player->pos.x - 16 * speed <= 1600
    && game->background->scene_background == CITY) {
        game->player->traveled_distance += 1;
        move_player_right(game, speed);
    }
    move_forest(game, speed);
}

int manage_key_d(game_t *game)
{
    if (game->event.key.code == sfKeyD) {
        game->player->move_right = true;
    }
    return (0);
}