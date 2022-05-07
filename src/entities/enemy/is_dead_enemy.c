/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** is_dead_enemy
*/

#include "struct_var.h"
#include "my.h"

bool is_dead_enemy(enemy_t *enemy)
{
    if (enemy == NULL) {
        return (false);
    }
    if (enemy->stat.actual_life <= 0) {
        return (true);
    } else {
        return (false);
    }
}
