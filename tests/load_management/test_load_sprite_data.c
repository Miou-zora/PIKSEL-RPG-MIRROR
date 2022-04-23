/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_load_sprite_data
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(load_sprite_data, casual_sprite_data_loading)
{
    sprite_data_t *sprite_data = load_sprite_data("tests/assets/PNG_transparency_demonstration_1.png");

    destroy_sprite_data(&sprite_data);
}

Test(load_sprite_data, no_sprite_data)
{
    sprite_data_t *sprite_data = load_sprite_data("tests/assets/no_sprite.png");

    cr_assert_null(sprite_data);
}