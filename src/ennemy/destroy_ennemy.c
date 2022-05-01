/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** destroy_armor
*/

#include "struct_var.h"

void destroy_ennemy(ennemy_t **ennemy)
{
    if (*ennemy) {
        if ((*ennemy)->name) {
            freen((void **)(*ennemy)->name);
        }
        if ((*ennemy)->sprite_data) {
            destroy_sprite_data(&((*ennemy)->sprite_data));
        }
        freen((void **)ennemy);
    }
}