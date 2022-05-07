/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_enemy
*/

#include "struct_var.h"
#include "my.h"

bool init_enemy(enemy_t **enemy)
{
    (*enemy) = load_enemy("scripts/enemy/wolf.ene");
    if ((*enemy) == NULL)
        return (true);
    (*enemy)->pos = (sfVector2f){500, 500};
    (*enemy)->attack_clock = create_clock_data();
    set_framerate_clock_data((*enemy)->attack_clock, 1);
    return (false);
}