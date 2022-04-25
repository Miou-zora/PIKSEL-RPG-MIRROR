/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** print_all_armors
*/

#include "struct_var.h"
#include "my.h"

void print_armor_type(int type)
{
    switch (type) {
        case 1:
            my_putstr("Helmet");
            break;
        case 2:
            my_putstr("Chestplate");
            break;
        case 3:
            my_putstr("Leggings");
            break;
        case 4:
            my_putstr("Boots");
            break;
        default:
            my_putstr("Unknown armor type or not_set");
            break;
    }
}

void print_type_bonus_basic(int type)
{
    switch (type) {
        case 1:
            my_putstr("Health");
            break;
        case 2:
            my_putstr("Regeneration");
            break;
        case 3:
            my_putstr("Power");
            break;
        case 4:
            my_putstr("Speed");
            break;
        case 5:
            my_putstr("Armor");
            break;
        case 6:
            my_putstr("Charisma");
            break;
        default:
            my_putstr("Unknown bonus type or not_set");
            break;
    }
}

void print_armor(armor_t *armor)
{
    if (armor == NULL)
        return;
    my_printf("Name: %s\n", armor->name);
    my_printf("\tId: %d\n", armor->id);
    my_printf("\tType armor: ");
    print_armor_type(armor->type_armor);
    my_printf("\n\tType bonus: ");
    print_type_bonus_basic(armor->type_bonus_basic);
    my_printf(
    "\n\tRarity: %i (the value is normaly a float so it can be unprecise)\n",
    (int)armor->rarity);
    my_printf("\tValue Bonus: %i\n", armor->value_bonus);
    if (armor->sprite_data != NULL) {
        my_printf("\tSprite: \033[32mloaded\033[39m\n");
    } else {
        my_printf("\tSprite: \033[31munloaded\033[39m\n");
    }
}

void print_all_armors(armor_t **armors)
{
    for (int i = 0; armors[i]; i++) {
        print_armor(armors[i]);
    }
}