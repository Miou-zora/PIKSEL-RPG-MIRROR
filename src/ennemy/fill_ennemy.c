/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** fill_armor
*/

#include "struct_var.h"
#include "my.h"

ennemy_t *fill_ennemy(ennemy_t *ennemy, char **data)
{
    if (data == NULL || get_len_array(data) != 8 || ennemy == NULL) {
        return (NULL);
    } else {
        ennemy->name = my_strdup(data[1]);
        if (ennemy->name == NULL) {
            return (NULL);
        }
        ennemy->sprite_data = load_sprite_data(data[7]);
        if (ennemy->sprite_data == NULL) {
            freen((void **)&(ennemy->name));
            return (NULL);
        }
        return (ennemy);
    }
}