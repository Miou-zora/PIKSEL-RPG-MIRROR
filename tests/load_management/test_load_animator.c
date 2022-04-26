/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_load_animator
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(load_animator, casual_animator_loading)
{
    animator_t *animator = load_animator("tests/scripts/iddle.ani");

    cr_assert_not_null(animator);
    cr_assert_eq(animator->number_image, 6);
    cr_assert_eq(animator->actual_image.x, 0);
    cr_assert_eq(animator->actual_image.y, 0);
    cr_assert_eq(animator->nbr_image_xy.x, 6);
    cr_assert_eq(animator->nbr_image_xy.y, 1);
    cr_assert_eq(animator->size_image.x, 48);
    cr_assert_eq(animator->size_image.y, 48);
    cr_assert_not_null(animator->sprite_data);
    destroy_animator(&animator);
}