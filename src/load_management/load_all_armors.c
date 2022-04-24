/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** load_all_armors
*/

#include "struct_var.h"
#include "my.h"

armor_t **load_all_armors(char *filepath)
{
    char **all_files = get_files_from_directory(filepath);
    armor_t **all_armors = create_all_armors(all_files);

    if (all_files == NULL || all_armors == NULL) {
        if (all_files != NULL)
            freen_array(&all_files);
        if (all_armors != NULL)
            freen(&all_armors);
        return (NULL);
    }
    if (fill_all_armors(all_armors, all_files) == NULL) {
        destroy_all_armors(&all_armors);
        freen_array(&all_files);
        return (NULL);
    }
    return (all_armors);
}