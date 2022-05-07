/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** detect_press_q_and_d
*/

#include "struct_var.h"
#include "my.h"

void detect_press_q_and_d(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        player->move_right = true;
        player->direction = true;
        if (player->player_mode == 1)
            player->walk->sprite_data->rect.top = 0;
        else if (player->player_mode == 2)
            player->run->sprite_data->rect.top = 0;
    } else
        player->move_left = false;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        player->move_left = true;
        player->direction = false;
        if (player->player_mode == 1)
            player->walk->sprite_data->rect.top = 48;
        else if (player->player_mode == 2)
            player->run->sprite_data->rect.top = 48;
    } else
        player->move_left = false;
}