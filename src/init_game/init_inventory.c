/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_inventory
*/

#include "struct_var.h"
#include "my.h"

bool init_inventory(inventory_t **inventory)
{
    (*inventory) = my_calloc(1, sizeof(inventory_t));
    (*inventory)->sprite_data = load_sprite_data("assets/items/Inventory.png");
    if ((*inventory)->sprite_data == NULL)
        return (true);
    sfSprite_setScale((*inventory)->sprite_data->sprite, (sfVector2f){2.1, 2.1});
    sfSprite_setPosition((*inventory)->sprite_data->sprite, (sfVector2f){300, 180});
    (*inventory)->boots = NULL;
    (*inventory)->chestplate = NULL;
    (*inventory)->helmet = NULL;
    (*inventory)->pant = NULL;
    (*inventory)->weapon = NULL;
    (*inventory)->display_inventory = false;
    return (false);
}