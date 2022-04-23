/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** initialize_armor
*/

#include "struct_var.h"
#include "my.h"

ennemy_t *create_ennemy(void)
{
    ennemy_t *ennemy = my_calloc(1, sizeof(*ennemy));

    if (ennemy) {
        ennemy->type_ennemy = NOT_SET;
        ennemy->name = NULL;
        ennemy->id = 0;
        ennemy->health = 0;
        ennemy->armor = 0;
        ennemy->power = 0;
        ennemy->speed = 0;
        ennemy->sprite_data = NULL;
    }
    return (ennemy);
}