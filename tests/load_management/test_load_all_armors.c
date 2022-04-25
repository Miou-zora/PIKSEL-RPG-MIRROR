/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_load_all_armors
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(load_all_armors, casual_all_armors_loading)
{
    armor_t **armors = load_all_armors("tests/scripts");

    cr_assert_not_null(armors);
    destroy_all_armors(&armors);
}

Test(load_all_armors, no_directory)
{
    armor_t **armors = load_all_armors("tests/not_a_directory");

    cr_assert_null(armors);
    destroy_all_armors(&armors);
}

Test(load_all_armors, no_scripts)
{
    armor_t **armors = load_all_armors("tests/directory_tests/sheesh");

    cr_assert_null(armors);
    destroy_all_armors(&armors);
}

Test(load_all_armors, nothing)
{
    armor_t **armors = load_all_armors(NULL);

    cr_assert_null(armors);
    destroy_all_armors(&armors);
}