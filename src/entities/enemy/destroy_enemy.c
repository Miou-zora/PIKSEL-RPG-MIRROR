/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** destroy_enemy
*/

#include "struct_var.h"

void destroy_enemy(enemy_t **enemy)
{
    if (enemy == NULL || *enemy == NULL)
        return;
    if ((*enemy)->name != NULL)
        freen(&((*enemy)->name));
    if ((*enemy)->stat != NULL)
        freen(&((*enemy)->stat));
    if ((*enemy)->animator_standing != NULL)
        destroy_animator(&((*enemy)->animator_standing));
    if ((*enemy)->animator_moving != NULL)
        destroy_animator(&((*enemy)->animator_moving));
    freen(enemy);
}
