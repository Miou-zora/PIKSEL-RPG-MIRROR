/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_z_event
*/

#include "struct_var.h"
#include "my.h"

int manage_key_z(game_t *game)
{
    if (game->event.key.code == sfKeyZ
    && game->background->menu->pause->display_pause == false) {
        game->player->move_up = true;
    }
    return (0);
}