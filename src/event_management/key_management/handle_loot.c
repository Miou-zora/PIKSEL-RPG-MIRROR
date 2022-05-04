/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** move_loot
*/

#include "struct_var.h"
#include "my.h"

void destroy_loot(loot_t *loot)
{
    if (loot->armor_or_weapon == 0) {
        destroy_armor(&loot->armor);
    } else if (loot->armor_or_weapon == 1) {
        destroy_weapon(&loot->weapon);
    }
}

void get_loot(game_t *game)
{
    sfVector2f loot_pos;
    loot_pos.x = game->background->loot->position.x - 100;
    loot_pos.y = game->background->loot->position.y - 200;
    if (game->player->pos.x >= loot_pos.x - 100 &&
    game->player->pos.x <= loot_pos.x + 100 &&
    game->player->pos.y >= loot_pos.y - 100 &&
    game->player->pos.y <= loot_pos.y + 100) {
        if (game->background->loot->armor_or_weapon == 0) {
            my_putstr(game->background->loot->armor->name);
            destroy_loot(game->background->loot);
        } else {
            my_putstr(game->background->loot->weapon->name);
            destroy_loot(game->background->loot);
        }
        game->background->loot = NULL;
    }
}

void move_loot(loot_t *loot, int to_move)
{
    loot->position.x += to_move;
    if (loot->armor_or_weapon == 0) {
        sfSprite_move(loot->armor->sprite_data->sprite,
        (sfVector2f){to_move, 0});
    }
    if (loot->armor_or_weapon == 1) {
        sfSprite_move(loot->weapon->sprite_data->sprite,
        (sfVector2f){to_move, 0});
    }
}