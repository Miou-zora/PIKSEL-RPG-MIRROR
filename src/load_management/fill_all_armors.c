/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** fill_all_armors
*/

#include "struct_var.h"
#include "my.h"

armor_t **fill_all_armors(armor_t **armors, char **all_files)
{
    for (int i = 0; all_files[i]; i++) {
        my_printf("%s\n", all_files[i]);
        armors[i] = load_armor(all_files[i]);
        if (armors[i] == NULL) {
            return (NULL);
        }
    }
    return (armors);
}