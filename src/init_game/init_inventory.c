/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_inventory
*/

#include "struct_var.h"
#include "my.h"

weapon_t *create_first_sword(void)
{
    weapon_t *weapon = my_calloc(1, sizeof(weapon_t));
    weapon->damage = 30;
    weapon->id = 1;
    weapon->name = "sword";
    weapon->rarity = 5;
    weapon->sprite_data = load_sprite_data("assets/items/sword.png");
    sfSprite_setPosition(weapon->sprite_data->sprite,
    (sfVector2f){1380, 245});
    sfSprite_setScale(weapon->sprite_data->sprite, (sfVector2f){2.1, 2.1});
    weapon->type_weapon = SWORD;
    return (weapon);
}

bool init_inventory(inventory_t **inventory)
{
    (*inventory) = my_calloc(1, sizeof(inventory_t));
    (*inventory)->sprite_data = load_sprite_data("assets/items/inventory.png");
    if ((*inventory)->sprite_data == NULL)
        return (true);
    sfSprite_setScale((*inventory)->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    sfSprite_setPosition((*inventory)->sprite_data->sprite,
    (sfVector2f){300, 180});
    (*inventory)->boots = NULL;
    (*inventory)->chestplate = NULL;
    (*inventory)->helmet = NULL;
    (*inventory)->pant = NULL;
    (*inventory)->weapon = create_first_sword();
    (*inventory)->display_inventory = false;
    return (false);
}
