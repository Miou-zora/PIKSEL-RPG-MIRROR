/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_enter_event
*/

#include "struct_var.h"
#include "my.h"

int manage_attack_key(game_t *game)
{
    if (game->event.key.code == sfKeyM) {
        game->player->attack = true;
        attack_enemy(game);
    }
    return (0);
}