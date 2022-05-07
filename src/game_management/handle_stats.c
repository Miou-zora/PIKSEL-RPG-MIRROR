/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_stats
*/

#include "struct_var.h"

void upgrade_level(stat_t *stat)
{
    if (stat->xp >= 100) {
        stat->level++;
        stat->xp -= 100;
        stat->health += 10;
        stat->actual_life += 10;
    }
}

void win_xp(stat_t *stat, int how_much_xp)
{
    stat->xp += how_much_xp;
}

void handle_stats(stat_t *stat)
{
    upgrade_level(stat);
}