/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

int manage_key_f(game_t *game)
{
    if (game->event.key.code == sfKeyF) {
        if (game->background->loot != NULL)
            get_loot(game);
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
    }
    return (0);
}