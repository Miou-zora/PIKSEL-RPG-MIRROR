/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_d_event
*/

#include "struct_var.h"
#include "my.h"

static void move_forest(game_t *game)
{
    if (game->background->scene_background == FOREST) {
        game->background->forest[0]->sprite->rect.left += 5;
        game->background->forest[1]->sprite->rect.left += 10;
        game->player->traveled_distance += 1;
        sfSprite_setTextureRect(game->background->forest[0]->sprite->sprite,
        game->background->forest[0]->sprite->rect);
        sfSprite_setTextureRect(game->background->forest[1]->sprite->sprite,
        game->background->forest[1]->sprite->rect);
    }
}

static void move_background(game_t *game)
{
    if (game->background->bedroom->sprite->rect.left < 300
    && game->background->scene_background == ROOM) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, -20);
        game->background->bedroom->sprite->rect.left += 5;
        game->player->traveled_distance += 1;
        sfSprite_setTextureRect(game->background->bedroom->sprite->sprite ,
        game->background->bedroom->sprite->rect);
    }
    if (game->background->scene_background == CITY) {
        if (game->background->loot != NULL)
            move_loot(game->background->loot, -20);
        game->background->town[0]->sprite->rect.left += 5;
        game->background->town[1]->sprite->rect.left += 10;
        game->player->traveled_distance += 1;
        sfSprite_setTextureRect(game->background->town[0]->sprite->sprite,
        game->background->town[0]->sprite->rect);
        sfSprite_setTextureRect(game->background->town[1]->sprite->sprite,
        game->background->town[1]->sprite->rect);
    }
    move_forest(game);
}

int manage_key_d(game_t *game)
{
    if (game->event.key.code == sfKeyD) {
        move_background(game);
        game->player->move_right = true;
    }
    return (0);
}