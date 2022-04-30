/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** load_all_weapons
*/

#include "struct_var.h"
#include "my.h"

weapon_t **load_all_weapons(char *path)
{
    char **all_files = get_files_from_directory(path, ".wea");
    weapon_t **all_weapons = create_all_weapons(all_files);

    if (all_files == NULL || all_weapons == NULL) {
        if (all_files != NULL) {
            freen_array(&all_files);
        }
        if (all_weapons != NULL) {
            freen(&all_weapons);
        }
        return (NULL);
    }
    if (fill_all_weapons(all_weapons, all_files) == NULL) {
        destroy_all_weapons(&all_weapons);
        freen_array(&all_files);
        return (NULL);
    }
    freen_array(&all_files);
    return (all_weapons);
}