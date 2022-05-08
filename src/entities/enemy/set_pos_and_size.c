/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** set_pos_and_size
*/

#include "struct_var.h"

void set_pos_and_size(enemy_t *enemy, sfVector2f pos, int size)
{
    enemy->pos = pos;
    enemy->size = size;
}