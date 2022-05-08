/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** forest_to_city
*/

#include "struct_var.h"
#include "my.h"

bool forest_to_city_display_text(game_t *game)
{
    if (game->player->traveled_distance > 25
    && game->player->traveled_distance < 30
    && game->background->scene_background == FOREST) {
        game->npc[2]->display_text = true;
        game->background->menu->pause->display_pause = true;
        sfSound_play(game->sound_music->terry);
        return (true);
    }
    return (false);
}

bool forest_to_city(game_t *game)
{
    if (game->player->traveled_distance > 25
    && game->player->traveled_distance < 30
    && game->background->scene_background == FOREST
    && game->npc[2]->display_text == true) {
        game->background->scene_background = CITY;
        game->npc[2]->display_text = false;
        game->player->traveled_distance = 530;
        game->npc[2]->sprite_data->pos = (sfVector2f){2000, 500};
        sfSprite_setPosition(game->npc[2]->sprite_data->sprite,
        game->npc[2]->sprite_data->pos);
        game->background->forest[0]->sprite->rect.left = 0;
        sfSprite_setTextureRect(game->background->forest[0]->sprite->sprite,
        game->background->forest[0]->sprite->rect);
        game->player->pos = (sfVector2f){820, 440};
        game->background->menu->pause->display_pause = false;
        sfSound_play(game->sound_music->teleport);
        return (true);
    }
    if (forest_to_city_display_text(game))
        return (true);
    return (false);
}