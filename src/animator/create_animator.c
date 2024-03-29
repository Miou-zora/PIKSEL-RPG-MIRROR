/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_animator
*/

#include "struct_var.h"
#include "my.h"
#include "stdlib.h"

animator_t *create_animator(void)
{
    animator_t *animator = malloc(sizeof(*animator));

    if (animator) {
        animator->actual_image = (sfVector2i){NOT_SET, NOT_SET};
        animator->clock_data = NULL;
        animator->nbr_image_xy = (sfVector2i){NOT_SET, NOT_SET};
        animator->number_image = NOT_SET;
        animator->size_image = (sfVector2f){NOT_SET, NOT_SET};
        animator->sprite_data = NULL;
    }
    return (animator);
}