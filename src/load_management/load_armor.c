/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** load_armor
*/

#include "struct_var.h"

armor_t *load_armor(char *path)
{
    armor_t *armor = create_armor();
    char **data = get_data_from_file(path);

    if (data == NULL || armor == NULL) {
        if (data != NULL) {
            freen((void **)&data);
        }
        if (armor != NULL) {
            destroy_armor(armor);
        }
        return (NULL);
    }
    return (armor);
}