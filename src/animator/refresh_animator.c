/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** refresh_animator
*/

#include "struct_var.h"

void refresh_animator(animator_t *animator)
{
    if (animator == NULL)
        return;
    animator->sprite_data->pos.x = animator->actual_image.x *
    animator->size_image.x;
    animator->sprite_data->pos.y = animator->actual_image.y *
    animator->size_image.y;
    animator->sprite_data->rect.top = animator->sprite_data->pos.y;
    animator->sprite_data->rect.left = animator->sprite_data->pos.x;
}
