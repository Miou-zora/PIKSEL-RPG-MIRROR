/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** manage_key_released
*/

#include "struct_var.h"

void manage_up_and_down(game_t *game)
{
    if (game->event.key.code == sfKeyZ) {
        game->player->move_up = false;
    }
    if (game->event.key.code == sfKeyS) {
        game->player->move_down = false;
    }
}

void manage_key_released(game_t *game)
{
    if (game->event.type == sfEvtKeyReleased) {
        if (game->event.key.code == sfKeyD) {
            game->player->move_right = false;
        }
        if (game->event.key.code == sfKeyQ) {
            game->player->move_left = false;
        }
        manage_up_and_down(game);
        (game->event.key.code == sfKeyLShift) ?
        game->player->player_mode = 1 : 0;
    }
}
