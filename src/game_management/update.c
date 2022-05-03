/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update
*/

#include "struct_var.h"

void update(game_t *game)
{
    if (game->background->menu->how_to_play_mode == true) {
        display_one_more_char(&game->background->menu->how_to_play);
    }
    // update_animator(game->enemy->animator_standing);
}