/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** player_attack_enemy
*/

#include "struct_var.h"
#include "my.h"

void sword_attack(game_t *game, sfVector2f enemy_pos, sfVector2f player_pos)
{
    if (enemy_pos.x > player_pos.x && enemy_pos.x < player_pos.x + 120 &&
    enemy_pos.y > player_pos.y - 200 && enemy_pos.y < player_pos.y + 200) {
        game->enemy->stat.actual_life -= 15;
    }
}

void spear_attack(game_t *game, sfVector2f enemy_pos, sfVector2f player_pos)
{
    if (enemy_pos.x > player_pos.x && enemy_pos.x < player_pos.x + 230 &&
    enemy_pos.y > player_pos.y - 100 && enemy_pos.y < player_pos.y + 100) {
        game->enemy->stat.actual_life -= 10;
    }
}

void gloves_attack(game_t *game, sfVector2f enemy_pos, sfVector2f player_pos)
{
    if (enemy_pos.x > player_pos.x && enemy_pos.x < player_pos.x + 100 &&
    enemy_pos.y > player_pos.y - 250 && enemy_pos.y < player_pos.y + 250) {
        game->enemy->stat.actual_life -= 10;
    }
}

void gun_attack(game_t *game, sfVector2f enemy_pos, sfVector2f player_pos)
{
    if (enemy_pos.x > player_pos.x && enemy_pos.x < player_pos.x + 500 &&
    enemy_pos.y > player_pos.y - 50 && enemy_pos.y < player_pos.y + 50) {
        game->enemy->stat.actual_life -= 30;
    }
}

void attack_enemy(game_t *game)
{
    sfVector2f enemy_pos = game->enemy->pos;
    sfVector2f player_pos = game->player->pos;
    player_pos.x += 170;
    player_pos.y += 100;
    void (*attacks[4])(game_t *game,
    sfVector2f enemy_pos, sfVector2f player_pos) =
    {sword_attack, spear_attack, gloves_attack, gun_attack};
    attacks[game->player->weapon - 1](game, enemy_pos, player_pos);
}