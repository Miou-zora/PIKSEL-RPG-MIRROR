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
        armor->id = 0;
        armor->type_armor = NOT_SET;
        armor->type_bonus_basic = NOT_SET;
        armor->rarity = 0;
        armor->value_bonus = 0;
        armor->sprite_data = NULL;
    }
    return (armor);
}