/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_inventory
*/

#include "struct_var.h"
#include "my.h"

void invert_display_of_inventory(inventory_t *inventory)
{
    if (inventory->display_inventory == false)
        inventory->display_inventory = true;
    else
        inventory->display_inventory = false;
}

void add_loot_to_inventory(inventory_t *inventory, loot_t *loot)
{
    void (*armors[4])(inventory_t *, loot_t *) =
    {add_helmet, add_chestplate, add_pant, add_boots};

    if (loot->armor_or_weapon == 1) {
        inventory->weapon = loot->weapon;
        sfSprite_setPosition(inventory->weapon->sprite_data->sprite,
        (sfVector2f){1380, 245});
        sfSprite_setScale(inventory->weapon->sprite_data->sprite,
        (sfVector2f){2.1, 2.1});
    } else if (loot->armor_or_weapon == 0) {
        armors[loot->armor->id - 1](inventory, loot);
    }
}