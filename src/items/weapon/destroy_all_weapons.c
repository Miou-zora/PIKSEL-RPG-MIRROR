/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** destroy_all_weapons
*/

#include "struct_var.h"
#include "my.h"

void destroy_all_weapons(weapon_t ***weapon)
{
    if (weapon && *weapon) {
        for (int i = 0; (*weapon)[i]; i++) {
            destroy_weapon(&((*weapon)[i]));
        }
        freen(weapon);
    }
}
