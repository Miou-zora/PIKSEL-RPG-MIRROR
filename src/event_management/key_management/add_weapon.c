/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** add_weapon
*/

#include "struct_var.h"
#include "my.h"

void add_weapon(inventory_t *inventory, loot_t *loot)
{
    weapon_t *temp = NULL;
    sfVector2f pos =
    sfSprite_getPosition(loot->weapon->sprite_data->sprite);
    sfVector2f scale =
    sfSprite_getScale(loot->weapon->sprite_data->sprite);
    if (inventory->helmet != NULL) {
        temp = malloc(sizeof(weapon_t));
        temp = inventory->weapon;
    }
    inventory->weapon = loot->weapon;
    sfSprite_setPosition(inventory->weapon->sprite_data->sprite,
    (sfVector2f){1380, 245});
    sfSprite_setScale(inventory->weapon->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    if (temp != NULL) {
        my_putstr("on repose l'ancienne arme");
        loot->weapon = temp;
        loot->armor_or_weapon = 1;
        sfSprite_setPosition(loot->weapon->sprite_data->sprite, pos);
        sfSprite_setScale(loot->weapon->sprite_data->sprite, scale);
    } else {
        loot->armor_or_weapon = 3;
    }
}