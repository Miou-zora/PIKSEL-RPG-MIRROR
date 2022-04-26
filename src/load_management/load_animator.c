/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** load_animator
*/

#include "struct_var.h"

animator_t *load_animator(char *path)
{
    animator_t *animator = create_animator();
    char **data = get_data_from_file(path);

    if (data == NULL || animator == NULL) {
        if (data != NULL) {
            freen(&(*data));
            freen(&data);
        }
        if (animator != NULL) {
            destroy_animator(&animator);
        }
        return (NULL);
    }
    if (fill_animator(animator, data) == NULL) {
        freen(&(*data));
        freen(&data);
        freen(&animator);
    }
    freen(&(*data));
    freen(&data);
    return (animator);
}