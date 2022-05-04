/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** spawn_random_loot
*/

#include "struct_var.h"
#include "my.h"

// int init_fist_loot_node(loot_t **loot, sfVector2f pos, char **pathes)
// {
//     int random_value = rand() % 4;

//     (*loot) = malloc(sizeof(loot_t));
//     (*loot)->id = 0;
//     (*loot)->next = NULL;
//     (*loot)->prev = NULL;
//     (*loot)->armor_or_weapon = rand() % 2;
//     (*loot)->position = pos;
//     if ((*loot)->armor_or_weapon == 0) {
//         (*loot)->weapon = NULL;
//         (*loot)->armor = load_armor(pathes[random_value]);
//         sfSprite_setPosition((*loot)->armor->sprite_data->sprite, pos);
//     } else {
//         (*loot)->armor = NULL;
//         (*loot)->weapon = load_weapon(pathes[random_value + 4]);
//         sfSprite_setPosition((*loot)->weapon->sprite_data->sprite, pos);
//     }
//     return (0);
// }

void spawn_random_loot(loot_t **loot, sfVector2f pos)
{
    char **pathes = get_data_from_file("scripts/loot/items_filepathes");
    int random_value = rand() % 4;

    (*loot) = malloc(sizeof(loot_t));
    (*loot)->armor_or_weapon = rand() % 2;
    (*loot)->position = pos;
    if ((*loot)->armor_or_weapon == 0) {
        (*loot)->weapon = NULL;
        (*loot)->armor = load_armor(pathes[random_value]);
        sfSprite_setPosition((*loot)->armor->sprite_data->sprite, pos);
        sfSprite_setColor((*loot)->armor->sprite_data->sprite, sfYellow);
    } else {
        (*loot)->armor = NULL;
        my_putstr(pathes[random_value + 4]);
        (*loot)->weapon = load_weapon(pathes[random_value + 4]);
        sfSprite_setPosition((*loot)->weapon->sprite_data->sprite, pos);
        sfSprite_setColor((*loot)->weapon->sprite_data->sprite, sfBlue);
    }
}