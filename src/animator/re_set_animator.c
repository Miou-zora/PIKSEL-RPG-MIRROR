/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** re_set_animator
*/

#include "struct_var.h"
#include "my.h"

void re_set_animator(animator_t **target, animator_t **giver)
{
    if ((*giver) != (*target)) {
        (*target) = (*giver);
        reset_clock_data((*target)->clock_data);
    }
}
