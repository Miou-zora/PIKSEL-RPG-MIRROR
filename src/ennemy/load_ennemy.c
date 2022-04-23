/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** load_ennemy
*/

#include "struct_var.h"
#include "my.h"

ennemy_t *load_ennemy(char *path)
{
    ennemy_t *ennemy = create_ennemy();
    char **data = get_data_from_file(path);

    if (data == NULL || ennemy == NULL) {
        if (data != NULL) {
            freen((void **)&data);
        }
        if (ennemy != NULL) {
            destroy_ennemy(&ennemy);
        }
        return (NULL);
    }
    if (fill_ennemy(ennemy, data) == NULL) {
        freen((void **)&data);
        freen((void **)&ennemy);
    }
    return (ennemy);
}