/*
** EPITECH PROJECT, 2022
** events_player
** File description:
** events_player
*/

#include "struct_var.h"

void key_run(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        player->player_mode = 2;
    else
        player->player_mode = 1;

    if (player->player_mode == 2) {
        player->player_walk = false;
        player->player_run = true;
    } else if (player->player_mode == 1) {
        player->player_walk = true;
        player->player_run = false;
    }
}

void move_player_up_and_down(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        player->move_up = true;
    else
        player->move_up = false;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        player->move_down = true;
    else
        player->move_down = false;
}

void detect_key(player_t *player)
{
    key_run(player);
    move_player_up_and_down(player);
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        player->move_left = true;
        if (player->player_mode == 1)
            player->walk->sprite_data->rect.top = 0;
        else if (player->player_mode == 2)
            player->run->sprite_data->rect.top = 0;
    } else
        player->move_left = false;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        player->move_right = true;
        if (player->player_mode == 1)
            player->walk->sprite_data->rect.top = 48;
        else if (player->player_mode == 2)
            player->run->sprite_data->rect.top = 48;
    } else
        player->move_right = false;
}

void analyse_events(player_t *player)
{
    if (player->event.type == sfEvtClosed)
        sfRenderWindow_close(player->window);
    detect_key(player);
}
