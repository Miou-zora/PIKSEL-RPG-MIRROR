/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** remove_loot
*/

#include "struct_var.h"
#include "my.h"

void remove_loot_clock(loot_t *loot[10], int i)
{
    drain_clock_data(loot[i]->disparition_clock);
    while (update_clock_data(loot[i]->disparition_clock)) {
        loot[i]->armor_or_weapon = 3;
    }
}

void remove_loot(loot_t *loot[10])
{
    for (int i = 0; i < 10; i++) {
        if (loot[i]->armor_or_weapon < 2) {
            remove_loot_clock(loot, i);
        }
    }
}