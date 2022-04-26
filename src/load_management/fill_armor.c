/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** fill_armor
*/

#include "struct_var.h"
#include "my.h"

static void set_armor_type(const char *str, armor_t *armor)
{
    char *types[] = {"helmet", "chestplate", "leggings", "boots"};

    armor->type_armor = 0;
    for (int i = 0; i < 4; i++) {
        if (my_strcmp(str, types[i]) == 0) {
            armor->type_armor = i + 1;
            return;
        }
    }
}

static void set_bonus_basic(const char *str, armor_t *armor)
{
    char *bonus[] = {"health", "regeneration", "power", "speed", "armor", "charisma"};

    armor->type_bonus_basic = 0;
    for (int i = 0; i < 4; i++) {
        if (my_strcmp(str, bonus[i]) == 0) {
            armor->type_bonus_basic = i + 1;
            return;
        }
    }
}

armor_t *fill_armor(armor_t *armor, char **data)
{
    if (data == NULL || get_len_array(data) != 8 || armor == NULL) {
        return (NULL);
    } else {
        armor->name = my_strdup(data[0]);
        if (armor->name == NULL) {
            return (NULL);
        }
        armor->sprite_data = load_sprite_data(data[6]);
        if (armor->sprite_data == NULL) {
            freen(&(armor->name));
            return (NULL);
        }
        armor->id = my_getnbr(data[1]);
        set_armor_type(data[2], armor);
        set_bonus_basic(data[3], armor);
        armor->rarity = my_getnbr(data[4]);
        armor->value_bonus = my_getnbr(data[5]);
        return (armor);
    }
}