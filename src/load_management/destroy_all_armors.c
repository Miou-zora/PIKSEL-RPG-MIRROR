/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** destroy_all_armors
*/

#include "struct_var.h"
#include "my.h"

void destroy_all_armors(armor_t ***armors)
{
    if (*armors == NULL)
        return;
    for (int i = 0; (*armors)[i] != NULL; i++) {
        destroy_armor(&((*armors)[i]));
    }
    freen(armors);
}