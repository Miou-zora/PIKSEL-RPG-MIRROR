/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_sprite_data
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(create_sprite_data, casual_sprite_data_creation)
{
    sprite_data_t *sprite_data = create_sprite_data();

    cr_assert_not_null(sprite_data);
    cr_assert_null(sprite_data->sprite);
    cr_assert_null(sprite_data->texture);
    cr_assert_eq(sprite_data->pos.x, 0);
    cr_assert_eq(sprite_data->pos.y, 0);
    cr_assert_eq(sprite_data->scale.x, 1);
    cr_assert_eq(sprite_data->scale.y, 1);
    cr_assert_eq(sprite_data->rect.left, 0);
    cr_assert_eq(sprite_data->rect.top, 0);
    cr_assert_eq(sprite_data->rect.width, 0);
    cr_assert_eq(sprite_data->rect.height, 0);
    destroy_sprite_data(&sprite_data);
}
