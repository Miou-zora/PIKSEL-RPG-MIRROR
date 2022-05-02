/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_menu
*/

#include "struct_var.h"
#include "my.h"

bool initialize_menu(menu_t **menu)
{
    (*menu) = my_calloc(1, sizeof(menu_t));
    if ((*menu) == NULL)
        return (true);
    (*menu)->sprite = load_sprite_data("assets/menu/menu.png");
    sfSprite_setScale((*menu)->sprite->sprite,
    (sfVector2f){8, 8});
    sfSprite_setPosition((*menu)->sprite->sprite,
    (sfVector2f){0, 0});
    return (false);
}