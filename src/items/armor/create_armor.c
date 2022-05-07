/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** initialize_armor
*/

#include "struct_var.h"
#include "my.h"

armor_t *create_armor(void)
{
    armor_t *armor = my_calloc(1, sizeof(*armor));

    if (armor) {
        armor->name = NULL;
        armor->id = NOT_SET;
        armor->type_armor = NOT_SET;
        armor->type_bonus_basic = NOT_SET;
        armor->rarity = NOT_SET;
        armor->value_bonus = NOT_SET;
        armor->sprite_data = NULL;
    }
    return (armor);
}