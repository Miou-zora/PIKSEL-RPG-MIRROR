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

static void select_weapon(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1))
        player->weapon = 1;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad2))
        player->weapon = 2;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad3))
        player->weapon = 3;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad4))
        player->weapon = 4;
}

int manage_key(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->event.key.code) == true) {
        if (game->event.key.code == sfKeySpace &&
        game->background->scene_background != MENU) {
            spawn_random_loot(game->background->loot, (sfVector2f){700, 600});
        }
        if (game->event.key.code == sfKeyE &&
        game->background->scene_background != MENU) {
            invert_display_of_inventory(game->player->inventory);
        }
        manage_key_z(game);
        manage_key_q(game);
        manage_key_s(game);
        manage_key_d(game);
        manage_key_f(game);
        manage_attack_key(game);
        select_weapon(game->player);
        if (game->event.key.code == sfKeyLShift)
            game->player->player_mode = 2;
        key_run(game->player);
        if (game->event.key.code == sfKeyT)
            sfSound_play(game->sound_music->damage);
        if (game->event.key.code == sfKeyY)
            sfSound_play(game->sound_music->teleport);
        if (game->event.key.code == sfKeyU)
            sfSound_play(game->sound_music->terry);
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