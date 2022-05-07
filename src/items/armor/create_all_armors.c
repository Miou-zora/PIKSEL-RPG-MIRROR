/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_all_armors
*/

#include "struct_var.h"
#include "my.h"

armor_t **create_all_armors(char **all_files)
{
    int nb_file = 0;
    armor_t **all_armors = NULL;

    if (all_files == NULL || all_files[0] == NULL)
        return (NULL);
    while (all_files[nb_file] != NULL) {
        nb_file++;
    }
    all_armors = my_calloc(nb_file + 1, sizeof(*all_armors));
    return (all_armors);
}