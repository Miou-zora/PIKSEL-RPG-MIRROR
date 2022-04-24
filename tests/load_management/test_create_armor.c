/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_armor
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(create_armor, casual_armor_creation)
{
    armor_t *armor = create_armor();

    cr_assert_not_null(armor);
    cr_assert_eq(armor->name, NULL);
    cr_assert_eq(armor->id, 0);
    cr_assert_eq(armor->type_armor, NOT_SET);
    cr_assert_eq(armor->type_bonus_basic, NOT_SET);
    cr_assert_eq(armor->rarity, 0);
    cr_assert_eq(armor->value_bonus, 0);
    cr_assert_eq(armor->sprite_data, NULL);
    destroy_armor(&armor);
}