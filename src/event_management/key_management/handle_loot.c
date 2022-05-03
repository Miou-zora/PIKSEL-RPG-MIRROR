/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** move_loot
*/

#include "struct_var.h"
#include "my.h"

void get_loot(game_t *game)
{
    sfVector2f loot_pos;
    loot_pos.x = game->background->loot->position.x - 100;
    loot_pos.y = game->background->loot->position.y - 200;
    if (game->player->pos.x >= loot_pos.x - 100 &&
    game->player->pos.x <= loot_pos.x + 100 &&
    game->player->pos.y >= loot_pos.y - 100 &&
    game->player->pos.y <= loot_pos.y + 100) {
        if (game->background->loot->armor_or_weapon == 0)
            my_putstr(game->background->loot->armor->name);
        else
            my_putstr(game->background->loot->weapon->name);
    }
}

void move_loot(loot_t *loot, int x_or_y, int to_move)
{
    if (x_or_y == 0)
        loot->position.x += to_move;
    if (x_or_y == 1)
        loot->position.y += to_move;
    if (loot->armor_or_weapon == 0) {
        if (x_or_y == 0)
            sfSprite_move(loot->armor->sprite_data->sprite,
            (sfVector2f){to_move, 0});
        else
            sfSprite_move(loot->armor->sprite_data->sprite,
            (sfVector2f){0, to_move});
    } else {
        if (x_or_y == 0)
            sfSprite_move(loot->weapon->sprite_data->sprite,
            (sfVector2f){to_move, 0});
        else
            sfSprite_move(loot->weapon->sprite_data->sprite,
            (sfVector2f){0, to_move});
    }
}