/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** print_all_weapons
*/

#include "struct_var.h"
#include "my.h"

void print_weapon_type(int type)
{
    switch (type) {
        case 1:
            my_putstr("Sword");
            break;
        case 2:
            my_putstr("Spear");
            break;
        case 3:
            my_putstr("Gloves");
            break;
        case 4:
            my_putstr("Gun");
            break;
        default:
            my_putstr("Unknown weapon type or not_set");
            break;
    }
}

void print_weapon(weapon_t *weapon)
{
    if (weapon == NULL)
        return;
    my_printf("Name: %s\n", weapon->name);
    my_printf("\tId: %d\n", weapon->id);
    my_printf("\tType weapon: ");
    print_weapon_type(weapon->type_weapon);
    my_printf("\n\tRarity: %i\n", weapon->rarity);
    my_printf("\tDamage Bonus: %i\n", weapon->damage);
    if (weapon->sprite_data != NULL) {
        my_printf("\tSprite: \033[32mloaded\033[39m\n");
    } else {
        my_printf("\tSprite: \033[31munloaded\033[39m\n");
    }
}

void print_all_weapons(weapon_t **weapons)
{
    if (weapons == NULL) {
        return;
    }
    for (int i = 0; weapons[i]; i++) {
        print_weapon(weapons[i]);
    }
}
