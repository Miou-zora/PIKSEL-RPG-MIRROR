/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** fill_weapon
*/

#include "struct_var.h"
#include <stdbool.h>
#include "my.h"

static void set_weapon_type(const char *str, weapon_t *weapon)
{
    char *types[] = {"sword", "spear", "gloves", "gun"};

    for (int i = 0; i < 4; i++) {
        if (my_strcmp(str, types[i]) == 0) {
            weapon->type_weapon = i + 1;
            return;
        }
    }
}

static bool check_error(weapon_t *weapon)
{
    bool error = false;
    error |= (weapon->name == NULL);
    error |= (weapon->sprite_data == NULL);
    error |= (weapon->id == NOT_SET);
    error |= (weapon->type_weapon == NOT_SET);
    error |= (weapon->rarity == NOT_SET);
    return (error);
}

weapon_t *fill_weapon(weapon_t *weapon, char **data)
{
    if (data == NULL || get_len_array(data) != 6 || weapon == NULL) {
        return (NULL);
    } else {
        weapon->name = my_strdup(data[0]);
        weapon->id = my_getnbr(data[1]);
        set_weapon_type(data[2], weapon);
        weapon->sprite_data = load_sprite_data(data[5]);
        weapon->damage = my_getnbr(data[3]);
        weapon->rarity = my_getnbr(data[4]);
        if (check_error(weapon)) {
            return (NULL);
        } else {
            return (weapon);
        }
    }
}