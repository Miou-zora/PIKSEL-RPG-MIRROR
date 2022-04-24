/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_get_file
*/

#include <criterion/criterion.h>
#include "struct_var.h"
#include "my.h"

void freec(void *ptr)
{
    void **the_ptr = (void **)ptr;

    free(*the_ptr);
    *the_ptr = NULL;
}

Test(get_file, casual_file_getting)
{
    char *file = get_file("tests/scripts/common_helmet.arm");

    cr_assert_not_null(file);
    freen(&file);
    cr_assert_null(file);
}