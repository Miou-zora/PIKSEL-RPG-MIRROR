/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_put_str_error
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(put_str_error, normal_put_str_error)
{
    cr_assert_eq(put_str_error(""), 0);
}

Test(put_str_error, nothing_in_str)
{
    cr_assert_eq(put_str_error(NULL), 0);
}