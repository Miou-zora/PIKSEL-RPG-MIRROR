/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** load_animator
*/

#include "struct_var.h"

animator_t *load_animator(char *path)
{
    animator_t *armor = create_animator();
    char **data = get_data_from_file(path);

    if (data == NULL || armor == NULL) {
        if (data != NULL) {
            freen(&(*data));
            freen(&data);
        }
        if (armor != NULL) {
            destroy_animator(&armor);
        }
        return (NULL);
    }
}