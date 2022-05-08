/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_weapon
*/

#include "struct_var.h"
#include <stdlib.h>

weapon_t *create_weapon(void)
{
    weapon_t *weapon = malloc(sizeof(*weapon));
    if (weapon) {
        weapon->name = NULL;
        weapon->id = NOT_SET;
        weapon->damage = NOT_SET;
        weapon->rarity = NOT_SET;
        weapon->sprite_data = NULL;
        weapon->type_weapon = NOT_SET;
    }
    return (weapon);
}