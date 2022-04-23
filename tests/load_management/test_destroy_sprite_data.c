/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** test_destroy_sprite_data
*/

#include <criterion/criterion.h>
#include "struct_var.h"

Test(destroy_sprite_data, casual_sprite_data_destrucyion)
{
    sprite_data_t *sprite_data = create_sprite_data();

    destroy_sprite_data(&sprite_data);
    cr_assert_null(sprite_data);
}
