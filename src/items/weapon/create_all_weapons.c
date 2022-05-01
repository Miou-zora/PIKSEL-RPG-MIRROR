/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** create_all_weapons
*/

#include "struct_var.h"
#include "my.h"

weapon_t **create_all_weapons(char **all_files)
{
    int nb_file = 0;
    weapon_t **all_weapons = NULL;

    if (all_files == NULL || all_files[0] == NULL)
        return (NULL);
    while (all_files[nb_file] != NULL) {
        nb_file++;
    }
    all_weapons = my_calloc(nb_file + 1, sizeof(*all_weapons));
    return (all_weapons);
}
