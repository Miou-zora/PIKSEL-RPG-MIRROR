/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

int manage_key_z(game_t *game)
{
    if (game->event.key.code == sfKeyZ) {
        game->player->move_up = true;
    }
    return (0);
}