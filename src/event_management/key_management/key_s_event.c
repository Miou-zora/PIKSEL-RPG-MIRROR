/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

int manage_key_s(game_t *game)
{
    if (game->event.key.code == sfKeyS) {
        game->player->move_down = true;
    }
    return (0);
}