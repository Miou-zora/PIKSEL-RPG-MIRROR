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

static void manage_key_pressed(game_t *game)
{
    manage_key_z(game);
    manage_key_q(game);
    manage_key_s(game);
    manage_key_d(game);
    manage_key_f(game);
    manage_key_q_f(game);
    manage_attack_key(game);
    select_weapon(game->player);
    if (game->event.key.code == sfKeyLShift)
        game->player->player_mode = 2;
    key_run(game->player);
    if (game->event.key.code == sfKeyT)
        sfSound_play(game->sound_music->damage);
}

int manage_key(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->event.key.code) == true) {
        if (game->event.key.code == sfKeyE
        && game->background->scene_background != MENU
        && game->background->scene_background != SETTINGS
        && game->background->scene_background != CINEMATIC
        && game->background->menu->pause->display_pause == false) {
            invert_display_of_inventory(game->player->inventory);
        }
        manage_key_pressed(game);
    }
    manage_key_released(game);
    return (0);
}

void manage_lose(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (game->is_dead) {
        if (game->event.type == sfEvtMouseButtonPressed
        && mouse_pos.x > 610 && mouse_pos.x < 1400 && mouse_pos.y > 795
        && mouse_pos.y < 950) {
            destroy_game(game);
        }
    }
}