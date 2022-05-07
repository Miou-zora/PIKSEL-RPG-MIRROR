/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** get_distance
*/

#include "struct_var.h"
#include <math.h>

float get_distance(sfVector2f a, sfVector2f b)
{
    return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}
