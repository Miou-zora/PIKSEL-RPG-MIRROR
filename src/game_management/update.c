/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update
*/

#include "struct_var.h"

void update(game_t *game)
{
    if (game->background->menu->how_to_play_mode == true)
        drain_clock_data(game->background->menu->how_to_play->text_clock);
    while (game->background->menu->how_to_play_mode == true &&
    update_clock_data(game->background->menu->how_to_play->text_clock)) {
        drain_clock_data(game->background->menu->how_to_play->text_clock);
        if (display_one_more_char(&game->background->menu->how_to_play)
        == false) {
            game->background->menu->how_to_play_mode = false;
        }
    }
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