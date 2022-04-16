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
    return (0);
}