/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** init sprite and data in rpg
*/

#include "my.h"
#include "struct_var.h"

int initialize_window(sfRenderWindow **window)
{
    sfVideoMode mode = {1920, 1080, 32};
    (*window) = sfRenderWindow_create(mode,
    "my_rpg", sfResize | sfClose, NULL);
    if ((*window) == NULL)
        return (84);
    return (0);
}