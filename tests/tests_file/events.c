/*
** EPITECH PROJECT, 2022
** events_player
** File description:
** events_player
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

void detect_key(player_t *player)
{
    key_run(player);
    move_player_up_and_down(player);
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        player->move_left = true;
        player->direction = true;
        if (player->player_mode == 1)
            player->walk->sprite_data->rect.top = 0;
        else if (player->player_mode == 2)
            player->run->sprite_data->rect.top = 0;
    } else
        player->move_left = false;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        player->move_right = true;
        player->direction = false;
        if (player->player_mode == 1)
            player->walk->sprite_data->rect.top = 48;
        else if (player->player_mode == 2)
            player->run->sprite_data->rect.top = 48;
    } else
        player->move_right = false;
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
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1))
        player->weapon = 1;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad2))
        player->weapon = 2;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad3))
        player->weapon = 3;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad4))
        player->weapon = 4;
}

void analyse_events(player_t *player)
{
    if (player->event.type == sfEvtClosed)
        sfRenderWindow_close(player->window);
    select_weapon(player);
    detect_key(player);
    player_attack(player);
}
