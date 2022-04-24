/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_load_armor
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(load_armor, casual_armor_loading)
{
    armor_t *armor = load_armor("tests/scripts/common_helmet.arm");

    cr_assert_not_null(armor);
    cr_assert_str_eq(armor->name, "common_helmet");
    destroy_armor(&armor);
};

Test(load_armor, no_script)
{
    armor_t *armor = load_armor("tests/scripts/no_armor.arm");

    cr_assert_null(armor);
};

Test(load_armor, null_value)
{
    armor_t *armor = load_armor(NULL);

    cr_assert_null(armor);
};