/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** test_load_weapon
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(load_weapon, casual_weapon_loading)
{
    weapon_t *weapon = load_weapon("tests/scripts/common_sword.wea");

    cr_assert_not_null(weapon);
    destroy_weapon(&weapon);
}

Test(load_weapon, no_script)
{
    weapon_t *weapon = load_weapon("no_script");

    cr_assert_null(weapon);
    destroy_weapon(&weapon);
}

Test(load_weapon, null_value)
{
    weapon_t *weapon = load_weapon(NULL);

    cr_assert_null(weapon);
    destroy_weapon(&weapon);
}