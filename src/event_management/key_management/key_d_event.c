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
    && game->player->pos.x > 800
    && game->player->pos.x < 831
    && game->background->scene_background == ROOM) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, -20);
        game->background->bedroom->sprite->rect.left += 5 * speed;
        game->player->traveled_distance += 1 * speed;
        sfSprite_setTextureRect(game->background->bedroom->sprite->sprite ,
        game->background->bedroom->sprite->rect);
    } else if ((game->background->bedroom->sprite->rect.left <= 0
    || game->background->bedroom->sprite->rect.left >= 300)  
    && game->player->pos.x - 16 * speed <= 1600
    && game->background->scene_background == ROOM) {
        move_player_right(game, speed);
    }
    if (game->background->scene_background == CITY
    && game->player->pos.x > 800
    && game->player->pos.x < 831) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, -20);
        game->background->town[0]->sprite->rect.left += 5 * speed;
        game->background->town[1]->sprite->rect.left += 10 * speed;
        game->player->traveled_distance += 1 * speed;
        sfSprite_setTextureRect(game->background->town[0]->sprite->sprite,
        game->background->town[0]->sprite->rect);
        sfSprite_setTextureRect(game->background->town[1]->sprite->sprite,
        game->background->town[1]->sprite->rect);
    } else if (game->background->town[0]->sprite->rect.left <= 0  
    && game->player->pos.x - 16 * speed <= 1600
    && game->background->scene_background == CITY) {
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