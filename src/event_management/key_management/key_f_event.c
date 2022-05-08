/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_f_event
*/

#include "struct_var.h"
#include "my.h"

int manage_background_tp(game_t *game)
{
    if (room_to_city(game))
        return (0);
    if (city_to_room(game))
        return (0);
    if (city_to_forest(game))
        return (0);
    if (forest_to_city(game))
        return (0);
    if (forest_to_labo(game))
        return (0);
    if (labo_to_forest(game))
        return (0);
    return (0);
}

void check_if_boss_dead(game_t *game)
{
    if (game->background->scene_background == LABO
    && game->player->pos.x + 20 >= game->npc[4]->sprite_data->pos.x
    && game->npc[4]->sprite_data->pos.x + 20 <= game->player->pos.x) {
        if (init_game(game))
            my_printf("fail");
    }
}

int manage_background(game_t *game)
{
    if (game->player->traveled_distance >= 90
    && game->player->traveled_distance <= 130
    && game->background->scene_background == CITY) {
        game->npc[0]->display_text = true;
        sfSound_play(game->sound_music->terry);
        return (0);
    } else
        game->npc[0]->display_text = false;
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
        if (game->player->traveled_distance >= 90
        && game->player->traveled_distance <= 130
        && game->background->scene_background == CITY
        && game->npc[0]->display_text == true) {
            game->npc[0]->display_text = false;
            return (0);
        }
        manage_background(game);
    }
    return (0);
}