/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_f_event
*/

#include "struct_var.h"
#include "my.h"

bool manage_forest(game_t *game)
{
    if (forest_to_city(game))
        return (true);
    if (forest_to_labo(game))
        return (true);
    if (labo_to_forest(game))
        return (true);
    return (false);
}

int manage_background_tp(game_t *game)
{
    if (room_to_city(game))
        return (0);
    if (city_to_room(game))
        return (0);
    if (city_to_forest(game))
        return (0);
    if (manage_forest(game))
        return (0);
    return (0);
}

void check_if_boss_dead(game_t *game)
{
    if (game->background->scene_background == LABO
    && game->player->pos.x + 100 >= game->npc[4]->sprite_data->pos.x
    && game->npc[4]->sprite_data->pos.x - 100 <= game->player->pos.x
    && game->npc[4]->display_text == true) {
        game->background->menu->pause->display_pause = false;
        game->npc[4]->display_text = false;
        destroy_game(game);
    } else if (game->background->scene_background == LABO
    && game->player->pos.x + 100 >= game->npc[4]->sprite_data->pos.x
    && game->npc[4]->sprite_data->pos.x - 100 <= game->player->pos.x) {
        game->npc[4]->display_text = true;
        sfSound_play(game->sound_music->terry);
        game->background->menu->pause->display_pause = true;
    }
}

int manage_background(game_t *game)
{
    if (game->player->traveled_distance >= 90
    && game->player->traveled_distance <= 130
    && game->background->scene_background == CITY
    && game->background->menu->pause->display_pause == true) {
        game->background->menu->pause->display_pause = false;
        game->npc[0]->display_text = false;
        return (0);
    } else if (game->player->traveled_distance >= 90
    && game->player->traveled_distance <= 130
    && game->background->scene_background == CITY) {
        game->npc[0]->display_text = true;
        sfSound_play(game->sound_music->terry);
        game->background->menu->pause->display_pause = true;
        return (0);
    }
    if (manage_background_tp(game))
        return (0);
    check_if_boss_dead(game);
    return (0);
}

int manage_key_f(game_t *game)
{
    if (game->event.key.code == sfKeyF) {
        if (game->background->loot != NULL)
            get_loot(game);
        manage_background(game);
    }
    return (0);
}
