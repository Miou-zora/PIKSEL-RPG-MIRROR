/*
** EPITECH PROJECT, 2022
** move_player
** File description:
** move_player
*/

#include "struct_var.h"

void move_player_walk(player_t *player)
{
    if (player->move_up == true && player->player_mode == 1)
        player->pos.y -= 0.5;
    if (player->move_down == true && player->player_mode == 1)
        player->pos.y += 0.5;
    if (player->move_left == true && player->player_mode == 1)
        player->pos.x += 0.5;
    if (player->move_right == true && player->player_mode == 1)
        player->pos.x -= 0.5;
}

void move_player_run(player_t *player)
{
    if (player->move_up == true && player->player_mode == 2)
        player->pos.y -= 1;
    if (player->move_down == true && player->player_mode == 2)
        player->pos.y += 1;
    if (player->move_left == true && player->player_mode == 2)
        player->pos.x += 1;
    if (player->move_right == true && player->player_mode == 2)
        player->pos.x -= 1;
}
