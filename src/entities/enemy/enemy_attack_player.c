/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** enemy_attack_player
*/

#include "struct_var.h"
#include "my.h"

void attack_player(enemy_t *enemy, player_t *player)
{
    sfVector2f enemy_pos;

    drain_clock_data(enemy->attack_clock);
    while (update_clock_data(enemy->attack_clock)) {
        enemy_pos.x = enemy->pos.x - 50;
        enemy_pos.y = enemy->pos.y - 100;
        if (enemy_pos.x <= player->pos.x + 75 &&
        enemy_pos.x >= player->pos.x - 75 && enemy_pos.y <= player->pos.y + 75 &&
        enemy_pos.y >= player->pos.y - 75)
            player->stat->actual_life -= 20;
    }
}