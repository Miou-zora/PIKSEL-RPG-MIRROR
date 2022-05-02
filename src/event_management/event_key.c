/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

int manage_key(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->event.key.code) == true) {
        manage_key_z(game);
        manage_key_q(game);
        manage_key_s(game);
        manage_key_d(game);
    }
    return (0);
}