/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** detect_press_q_and_d
*/

#include "struct_var.h"
#include "my.h"

void do_something(game_t *game)
{
    manage_key(game);
    manage_pause(game);
    detect_key(game->player, game->clock_secondary, game);
    player_attack(game->player);
    manage_lose(game);
}

void detect_press_q_and_d(player_t *player, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)
    && game->background->menu->pause->display_pause == false) {
        player->move_right = true;
        player->direction = true;
        (player->player_mode == 1) ?
        player->walk->sprite_data->rect.top = 0 : 0;
        (player->player_mode == 2) ?
        player->run->sprite_data->rect.top = 0 : 0;
    } else
        player->move_left = false;
    if (sfKeyboard_isKeyPressed(sfKeyQ)
    && game->background->menu->pause->display_pause == false) {
        player->move_left = true;
        player->direction = false;
        (player->player_mode == 1) ?
        player->walk->sprite_data->rect.top = 48 : 0;
        (player->player_mode == 2) ?
        player->run->sprite_data->rect.top = 48 : 0;
    } else
        player->move_left = false;
}
