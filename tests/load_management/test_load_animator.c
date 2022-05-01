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
    cr_assert_eq(animator->number_image, 8);
    cr_assert_eq(animator->actual_image.x, 0);
    cr_assert_eq(animator->actual_image.y, 0);
    cr_assert_eq(animator->nbr_image_xy.x, 4);
    cr_assert_eq(animator->nbr_image_xy.y, 2);
    cr_assert_eq(animator->size_image.x, 148);
    cr_assert_eq(animator->size_image.y, 115);
    cr_assert_not_null(animator->sprite_data);
    destroy_animator(&animator);
}
