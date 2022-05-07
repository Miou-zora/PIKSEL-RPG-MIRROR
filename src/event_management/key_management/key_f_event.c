/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_f_event
*/

#include "struct_var.h"
#include "my.h"

int manage_background(game_t *game)
{
    if (game->player->traveled_distance >= 90
    && game->player->traveled_distance <= 130
    && game->background->scene_background == CITY) {
        game->npc[0]->display_text = true;
        return (0);
    } else
        game->npc[0]->display_text = false;
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