/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_get_file
*/

#include <criterion/criterion.h>
#include "struct_var.h"
#include "my.h"

Test(get_file, casual_file_getting)
{
    char *file = get_file("tests/scripts/common_helmet.arm");

    my_printf("%i", my_strlen(file));
    cr_assert_not_null(file);
}