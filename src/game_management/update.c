/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update
*/

#include "struct_var.h"

void update(game_t *game)
{
    update_how_to_play(game->background->menu);
    update_animator(game->player->iddle);
    if (game->player->player_mode == 1
    && detect_if_key_pressed(game->player) == 0)
        update_animator(game->player->walk);
    if (game->player->player_mode == 2)
        update_animator(game->player->run);
    if (detect_if_key_pressed(game->player) == 0)
        update_animator(game->player->iddle);

    if (game->player->attack == true && game->player->weapon == 1) {
        update_animator(game->player->sword);
    }
    // update_animator(game->enemy->animator_standing);
}