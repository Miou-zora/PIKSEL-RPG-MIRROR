/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** update_animator
*/

#include "struct_var.h"

void update_animator(animator_t *animator)
{
    if (animator == NULL)
        return;
    drain_clock_data(animator->clock_data);
    if (update_clock_data(animator->clock_data)) {
        increment_animator_image_pos(animator);
    }
    refresh_animator(animator);
    if (animator->sprite_data != NULL)
        sfSprite_setTextureRect(animator->sprite_data->sprite,
        animator->sprite_data->rect);
}
