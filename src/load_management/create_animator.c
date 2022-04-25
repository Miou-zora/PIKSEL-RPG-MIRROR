/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_animator
*/

#include "struct_var.h"
#include "stdlib.h"

animator_t *create_animator(void)
{
    animator_t *animator = malloc(sizeof(*animator));

    if (animator == NULL)
        return (NULL);
    animator->actual_image = (sfVector2i){0, 0};
    animator->clock_data = NULL;
    animator->nbr_image_xy = (sfVector2i){0, 0};
    animator->number_image = 0;
    animator->size_image = (sfVector2f){0.f, 0.f};
    animator->sprite_data = NULL;
    return (animator);
}