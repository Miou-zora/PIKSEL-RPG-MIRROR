/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

static void key_run(player_t *player)
{
    player->player_mode = (sfKeyboard_isKeyPressed(sfKeyLShift)) ? 2 : 1;
    if (player->player_mode == 2) {
        player->player_walk = false;
        player->player_run = true;
    } else if (player->player_mode == 1) {
        player->player_walk = true;
        player->player_run = false;
    }
}

void detect_key(player_t *player, clock_data_t *clock, game_t *game)
{
    key_run(player);
    drain_clock_data(clock);
    while (update_clock_data(clock)) {
        detect_press_q_and_d(player, game);
    }
}

void player_attack(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        player->player_walk = false;
        player->player_run = false;
        player->move_up = false;
        player->move_down = false;
        player->move_left = false;
        player->move_right = false;
        player->attack = true;
    }
}

void select_weapon(player_t *player)
{
    if (player->inventory->weapon != NULL) {
        player->weapon = player->inventory->weapon->id;
    }
}

int event_handler(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->background->scene_background == MENU)
            handle_menu_events(game);
        (game->background->scene_background == SETTINGS) ?
        handle_settings_events(game) : 0;
        if (sfKeyboard_isKeyPressed(game->event.key.code) == true
        && game->event.key.code == sfKeySpace
        && game->background->scene_background == CINEMATIC) {
            game->background->scene_background = ROOM;
            game->background->last_scene_background = CINEMATIC;
        }
        do_something(game);
        select_weapon(game->player);
    }
    return (0);
}
