/*
** EPITECH PROJECT, 2022
** detect_key
** File description:
** detect_key
*/

#include "struct_var.h"

int detect_if_key_pressed(player_t *player)
{
    if (player->move_up == false && player->move_down == false &&
    player->move_left == false && player->move_right == false)
        return (1);
    return (0);
}
