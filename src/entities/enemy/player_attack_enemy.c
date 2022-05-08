/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** player_attack_enemy
*/

#include "struct_var.h"
#include "my.h"
#include <stdio.h>

void sword_attack(sfVector2f enemy_pos,
sfVector2f player_pos, enemy_t *enemy, bool direction)
{
    if (direction == true) {
        if (enemy_pos.x > player_pos.x && enemy_pos.x < player_pos.x + 150 &&
        enemy_pos.y > player_pos.y - 200 && enemy_pos.y < player_pos.y + 200) {
            enemy->stat.actual_life -= 30;
        }
    } else {
        player_pos.x -= 170;
        if (enemy_pos.x > player_pos.x - 150 && enemy_pos.x < player_pos.x &&
        enemy_pos.y > player_pos.y - 200 && enemy_pos.y < player_pos.y + 200) {
            enemy->stat.actual_life -= 30;
        }
    }
}

void spear_attack(sfVector2f enemy_pos,
sfVector2f player_pos, enemy_t *enemy, bool direction)
{
    if (direction == true) {
        if (enemy_pos.x > player_pos.x && enemy_pos.x < player_pos.x + 230 &&
        enemy_pos.y > player_pos.y - 100 && enemy_pos.y < player_pos.y + 100) {
            enemy->stat.actual_life -= 20;
        }
    } else {
        player_pos.x -= 170;
        if (enemy_pos.x > player_pos.x - 230 && enemy_pos.x < player_pos.x &&
        enemy_pos.y > player_pos.y - 100 && enemy_pos.y < player_pos.y + 100) {
            enemy->stat.actual_life -= 20;
        }
    }
}

void gloves_attack(sfVector2f enemy_pos,
sfVector2f player_pos, enemy_t *enemy, bool direction)
{
    if (direction == true) {
        if (enemy_pos.x > player_pos.x && enemy_pos.x < player_pos.x + 100 &&
        enemy_pos.y > player_pos.y - 250 && enemy_pos.y < player_pos.y + 250) {
            enemy->stat.actual_life -= 20;
        }
    } else {
        player_pos.x -= 170;
        if (enemy_pos.x > player_pos.x - 100 && enemy_pos.x < player_pos.x &&
        enemy_pos.y > player_pos.y - 250 && enemy_pos.y < player_pos.y + 250) {
            enemy->stat.actual_life -= 20;
        }
    }
}

void gun_attack(sfVector2f enemy_pos,
sfVector2f player_pos, enemy_t *enemy, bool direction)
{
    if (direction == true) {
        if (enemy_pos.x > player_pos.x && enemy_pos.x < player_pos.x + 500 &&
        enemy_pos.y > player_pos.y - 50 && enemy_pos.y < player_pos.y + 50) {
            enemy->stat.actual_life -= 60;
        }
    } else {
        player_pos.x -= 170;
        if (enemy_pos.x > player_pos.x - 500 && enemy_pos.x < player_pos.x &&
        enemy_pos.y > player_pos.y - 50 && enemy_pos.y < player_pos.y + 50) {
            enemy->stat.actual_life -= 60;
        }
    }
}

void attack_enemy(enemy_t *enemy, game_t *game)
{
    sfVector2f enemy_pos = enemy->pos;
    sfVector2f player_pos = game->player->pos;
    player_pos.x += 170;
    player_pos.y += 100;
    void (*attacks[4])(sfVector2f enemy_pos,
    sfVector2f player_pos, enemy_t *enemy, bool direction) =
    {sword_attack, spear_attack, gloves_attack, gun_attack};
    attacks[game->player->weapon - 1](enemy_pos,
    player_pos, enemy, game->player->direction);
}