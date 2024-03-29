/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** destroy_armor
*/

#include "struct_var.h"
#include "my.h"

void destroy_armor(armor_t **armor)
{
    if (*armor) {
        if ((*armor)->name) {
            freen(&((*armor)->name));
        }
        if ((*armor)->sprite_data) {
            destroy_sprite_data(&((*armor)->sprite_data));
        }
        freen(armor);
    }
}