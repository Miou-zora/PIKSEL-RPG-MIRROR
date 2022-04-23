/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_freen
*/

#include <criterion/criterion.h>
#include "my.h"
#include "struct_var.h"

Test(freen, normal_free)
{
    char *str = my_strdup("test");
    char *str3 = my_strdup("test2");
    char *str2 = NULL;

    (void)str3;
    freen((void **)&str);
    cr_assert_eq(str, NULL);
    freen((void **)&str2);
    cr_assert_eq(str2, NULL);
}