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
    sfIntRect rect_ene = {enemy_pos.x, enemy_pos.y,
    enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x,
    enemy->actual_animator->size_image.y *
    enemy->actual_animator->sprite_data->scale.y};
    sfIntRect rect_player = {player_pos.x + 30, player_pos.y, 125, 200};

    if (direction == true) {
        (sfIntRect_intersects(&rect_ene, &rect_player, NULL)) ?
        enemy->stat.actual_life -= 10 : 0;
    } else {
        rect_player.left -= 30;
        rect_player.left -= 200;
        if (sfIntRect_intersects(&rect_ene, &rect_player, NULL))
            enemy->stat.actual_life -= 10;
    }
}

void spear_attack(sfVector2f enemy_pos,
sfVector2f player_pos, enemy_t *enemy, bool direction)
{
    sfIntRect rect_ene = {enemy_pos.x, enemy_pos.y,
    enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x,
    enemy->actual_animator->size_image.y *
    enemy->actual_animator->sprite_data->scale.y};
    sfIntRect rect_player = {player_pos.x + 30, player_pos.y + 30, 300, 100};

    if (direction == true) {
        (sfIntRect_intersects(&rect_ene, &rect_player, NULL)) ?
        enemy->stat.actual_life -= 25 : 0;
    } else {
        rect_player.left -= 30;
        rect_player.left -= 300;
        if (sfIntRect_intersects(&rect_ene, &rect_player, NULL))
            enemy->stat.actual_life -= 25;
    }
}

void gloves_attack(sfVector2f enemy_pos,
sfVector2f player_pos, enemy_t *enemy, bool direction)
{
    sfIntRect rect_ene = {enemy_pos.x, enemy_pos.y,
    enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x,
    enemy->actual_animator->size_image.y *
    enemy->actual_animator->sprite_data->scale.y};
    sfIntRect rect_player = {player_pos.x + 30, player_pos.y - 30, 100, 300};

    if (direction == true) {
        (sfIntRect_intersects(&rect_ene, &rect_player, NULL)) ?
        enemy->stat.actual_life -= 25 : 0;
    } else {
        rect_player.left -= 30;
        rect_player.left -= 200;
        if (sfIntRect_intersects(&rect_ene, &rect_player, NULL))
            enemy->stat.actual_life -= 25;
    }
}

void gun_attack(sfVector2f enemy_pos,
sfVector2f player_pos, enemy_t *enemy, bool direction)
{
    sfIntRect rect_ene = {enemy_pos.x, enemy_pos.y,
    enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x,
    enemy->actual_animator->size_image.y *
    enemy->actual_animator->sprite_data->scale.y};
    sfIntRect rect_player = {player_pos.x + 10, player_pos.y + 30, 500, 20};

    if (direction == true) {
        (sfIntRect_intersects(&rect_ene, &rect_player, NULL)) ?
        enemy->stat.actual_life -= 20 : 0;
    } else {
        rect_player.left -= 20;
        rect_player.left -= 500;
        (sfIntRect_intersects(&rect_ene, &rect_player, NULL)) ?
        enemy->stat.actual_life -= 20 : 0;
    }
}

void attack_enemy(enemy_t *enemy, game_t *game)
{
    void (*attacks[4])(sfVector2f enemy_pos,
    sfVector2f player_pos, enemy_t *enemy, bool direction) =
    {sword_attack, spear_attack, gloves_attack, gun_attack};
    sfVector2f enemy_pos;
    sfVector2f player_pos;
    if (enemy->scene != game->background->scene_background)
        return;

    enemy_pos = enemy->pos;
    player_pos = game->player->pos;
    player_pos.x += 170;
    player_pos.y += 100;
    attacks[game->player->weapon - 1](enemy_pos,
    player_pos, enemy, game->player->direction);
}
