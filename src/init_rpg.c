/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** init sprite and data in rpg
*/

#include "my.h"
#include "rpg.h"

int initialize_menu(game_t *game)
{
    game->sprite->background[0] = malloc(sizeof(background_t));

    game->sprite->background[0]->name = "menu";
    game->sprite->background[0]->sprite->pos = (sfVector2f){0, 0};
}

int initialize_var(game_t *game)
{
    if (initialize_game(game) == 84 || initialize_game_end(game) == 84
    || initialize_how_to_play(game) == 84 || initialize_intro(game) == 84
    || initialize_menu(game) == 84 || initialize_options(game) == 84
    || initialize_pause(game) == 84 || initialize_cursor(game) == 84)
        return (84);
    return (0);
}