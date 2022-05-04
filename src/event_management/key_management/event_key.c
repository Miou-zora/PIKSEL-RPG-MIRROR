/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** event_key
*/

#include "struct_var.h"
#include "my.h"

void key_run(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        player->player_mode = 2;
        player->player_walk = false;
        player->player_run = true;
    } else {
        player->player_walk = true;
        player->player_run = false;
        player->player_mode = 1;
    }
}

int manage_key(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->event.key.code) == true) {
        if (game->event.key.code == sfKeySpace &&
        game->background->scene_background != MENU) {
            spawn_random_loot(&(game->background->loot), (sfVector2f){700, 600});
        }
        manage_key_z(game);
        manage_key_q(game);
        manage_key_s(game);
        manage_key_d(game);
        manage_key_f(game);
        manage_key_enter(game);
        if (game->event.key.code == sfKeyLShift)
            game->player->player_mode = 2;
        key_run(game->player);
    }
    if (game->event.type == sfEvtKeyReleased) {
        if (game->event.key.code == sfKeyD) {
            game->player->move_right = false;
        }
        if (game->event.key.code == sfKeyQ) {
            game->player->move_left = false;
        }
        if (game->event.key.code == sfKeyZ) {
            game->player->move_up = false;
        }
        if (game->event.key.code == sfKeyS) {
            game->player->move_down = false;
        }
        if (game->event.key.code == sfKeyLShift) {
            game->player->player_mode = 1;
        }
    }
    return (0);
}