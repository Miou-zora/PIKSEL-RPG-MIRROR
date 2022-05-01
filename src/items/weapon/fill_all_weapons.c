/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** fill_all_weapons
*/

#include "struct_var.h"

weapon_t **fill_all_weapons(weapon_t **weapons, char **all_files)
{
    for (int i = 0; all_files[i]; i++) {
        weapons[i] = load_weapon(all_files[i]);
        if (weapons[i] == NULL) {
            return (NULL);
        }
    }
    return (weapons);
}