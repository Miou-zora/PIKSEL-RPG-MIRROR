/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

int manage_key_enter(game_t *game)
{
    if (game->event.key.code == sfKeyEnter) {
        game->player->attack = true;
    }
    return (0);
}