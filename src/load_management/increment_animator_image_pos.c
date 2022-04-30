/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** increment_animator_image_pos
*/

#include "struct_var.h"

void increment_animator_image_pos(animator_t *animator)
{
    if (animator == NULL)
        return;
    animator->actual_image.x++;
    if (animator->actual_image.x + 1 + animator->nbr_image_xy.x *
    animator->actual_image.y > animator->number_image) {
        animator->actual_image.x = 0;
        animator->actual_image.y = 0;
    }
    if (animator->actual_image.x >= animator->nbr_image_xy.x) {
        animator->actual_image.x = 0;
        animator->actual_image.y++;
        if (animator->actual_image.y >= animator->nbr_image_xy.y)
            animator->actual_image.y = 0;
    }
}
