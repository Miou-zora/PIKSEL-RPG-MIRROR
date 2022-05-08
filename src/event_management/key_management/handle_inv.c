/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_inventory
*/

#include "struct_var.h"
#include "my.h"

void free_loot(loot_t *loot)
{
    if (loot->armor != NULL)
        destroy_armor(&loot->armor);
    if (loot->weapon != NULL)
        destroy_weapon(&loot->weapon);
    destroy_clock_data(&loot->disparition_clock);
    freen(&loot);
}

void invert_display_of_inventory(inventory_t *inventory)
{
    if (inventory->display_inventory == false)
        inventory->display_inventory = true;
    else
        inventory->display_inventory = false;
}

void add_loot_to_inventory(inventory_t *inventory, loot_t *loot)
{
    void (*armors[5])(inventory_t *, loot_t *) =
    {add_weapon, add_helmet, add_chestplate, add_pant, add_boots};

    if (loot->armor_or_weapon == 1) {
        armors[0](inventory, loot);
    } else if (loot->armor_or_weapon == 0) {
        armors[loot->armor->id](inventory, loot);
    }
}