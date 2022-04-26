/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** destroy_weapon
*/

#include "struct_var.h"

void destroy_weapon(weapon_t **weapon)
{
    if (weapon == NULL || *weapon == NULL)
        return;
    if ((*weapon)->name)
        freen(&((*weapon)->name));
    if ((*weapon)->sprite_data)
        destroy_sprite_data(&((*weapon)->sprite_data));
    freen(weapon);
}