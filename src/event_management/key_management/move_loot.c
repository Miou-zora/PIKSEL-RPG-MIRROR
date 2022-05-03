/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** move_loot
*/

#include "struct_var.h"

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