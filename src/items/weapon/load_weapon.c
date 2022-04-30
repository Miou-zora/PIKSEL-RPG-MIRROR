/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** load_weapon
*/

#include "struct_var.h"

weapon_t *load_weapon(char *filepath)
{
    weapon_t *weapon = create_weapon();
    char **data = get_data_from_file(filepath);

    if (data == NULL || weapon == NULL) {
        if (data != NULL) {
            freen(&(*data));
            freen(&data);
        }
        if (weapon != NULL) {
            destroy_weapon(&weapon);
        }
        return (NULL);
    }
    if (fill_weapon(weapon, data) == NULL) {
        freen(&(*data));
        freen(&data);
        destroy_weapon(&weapon);
    }
    freen(&(*data));
    freen(&data);
    return (weapon);
}