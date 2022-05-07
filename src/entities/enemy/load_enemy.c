/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** load_enemy
*/

#include "struct_var.h"
#include "my.h"

enemy_t *load_enemy(char *path)
{
    enemy_t *enemy = create_enemy();
    char **data = get_data_from_file(path);

    if (data == NULL || enemy == NULL) {
        if (data != NULL) {
            freen(&(*data));
            freen(&data);
        }
        if (enemy != NULL) {
            destroy_enemy(&enemy);
        }
        return (NULL);
    }
    if (fill_enemy(enemy, data) == NULL) {
        destroy_enemy(&enemy);
    }
    freen(&(*data));
    freen(&data);
    return (enemy);
}
