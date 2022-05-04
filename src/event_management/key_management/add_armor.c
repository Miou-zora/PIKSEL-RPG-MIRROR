/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** add_armor
*/

#include "struct_var.h"
#include "my.h"

void add_helmet(inventory_t *inventory, loot_t *loot)
{
    armor_t *temp = NULL;
    if (inventory->helmet != NULL) {
        temp = malloc(sizeof(armor_t));
        temp = inventory->helmet;
    }
    inventory->helmet = loot->armor;
    sfSprite_setPosition(inventory->helmet->sprite_data->sprite,
    (sfVector2f){355, 245});
    sfSprite_setScale(inventory->helmet->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    if (temp != NULL) {
        loot->armor = temp;
        loot->armor_or_weapon = 0;
    }
}

void add_chestplate(inventory_t *inventory, loot_t *loot)
{
    armor_t *temp = NULL;
    if (inventory->chestplate != NULL) {
        temp = malloc(sizeof(armor_t));
        temp = inventory->chestplate;
    }
    inventory->chestplate = loot->armor;
    sfSprite_setPosition(inventory->chestplate->sprite_data->sprite,
    (sfVector2f){355, 530});
    sfSprite_setScale(inventory->chestplate->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    if (temp != NULL) {
        my_putstr("on repose l'ancien equipement");
        loot->armor = temp;
        loot->armor_or_weapon = 0;
    }
}

void add_pant(inventory_t *inventory, loot_t *loot)
{
    armor_t *temp = NULL;
    if (inventory->pant != NULL) {
        temp = malloc(sizeof(armor_t));
        temp = inventory->pant;
    }
    inventory->pant = loot->armor;
    sfSprite_setPosition(inventory->pant->sprite_data->sprite,
    (sfVector2f){658, 245});
    sfSprite_setScale(inventory->pant->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    if (temp != NULL) {
        my_putstr("on repose l'ancien equipement");
        loot->armor = temp;
        loot->armor_or_weapon = 0;
    }
}

void add_boots(inventory_t *inventory, loot_t *loot)
{
    armor_t *temp = NULL;
    if (inventory->boots != NULL) {
        temp = malloc(sizeof(armor_t));
        temp = inventory->boots;
    }
    inventory->boots = loot->armor;
    sfSprite_setPosition(inventory->boots->sprite_data->sprite,
    (sfVector2f){658, 530});
    sfSprite_setScale(inventory->boots->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    if (temp != NULL) {
        my_putstr("on repose l'ancien equipement");
        loot->armor = temp;
        loot->armor_or_weapon = 0;
    }
}