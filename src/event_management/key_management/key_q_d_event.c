/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_q_d_event
*/

#include "struct_var.h"
#include "my.h"

int manage_key_q_f(game_t *game)
{
    if (game->event.key.code == sfKeyD && game->event.key.code == sfKeyQ &&
    game->background->menu->pause->display_pause == false) {
        game->player->move_right = false;
        game->player->move_left = false;
    }
    return (0);
}