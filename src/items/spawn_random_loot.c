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

void set_armor_or_weapon(loot_t **loot, sfColor *colors, sfVector2f pos)
{
    char **pathes = get_data_from_file("scripts/loot/items_filepathes");
    (*loot)->armor_or_weapon = rand() % 2;
    int random_value = rand() % 4;
    int clr = rand() % 16;
    if ((*loot)->armor_or_weapon == 0) {
        (*loot)->weapon = NULL;
        (*loot)->armor = load_armor(pathes[random_value]);
        sfSprite_setPosition((*loot)->armor->sprite_data->sprite, pos);
        sfSprite_setColor((*loot)->armor->sprite_data->sprite, colors[clr]);
    } else {
        (*loot)->armor = NULL;
        (*loot)->weapon = load_weapon(pathes[random_value + 4]);
        sfSprite_setPosition((*loot)->weapon->sprite_data->sprite, pos);
        sfSprite_setColor((*loot)->weapon->sprite_data->sprite, colors[clr]);
    }
}

void spawn_random_loot(loot_t **loot, sfVector2f pos)
{
    int which_loot = 0;
    sfColor colors[15] = {sfWhite, sfWhite, sfWhite, sfWhite, sfWhite,
    sfGreen, sfGreen, sfGreen, sfGreen, sfBlue, sfBlue, sfBlue, sfRed, sfRed,
    sfYellow};

    for (; loot[which_loot]->armor_or_weapon != 2 &&
    loot[which_loot]->armor_or_weapon != 3 && which_loot < 9; which_loot++);
    if (which_loot < 9) {
        loot[which_loot] = malloc(sizeof(loot_t));
        loot[which_loot]->position = pos;
        set_armor_or_weapon(&(loot[which_loot]), colors, pos);
    }
}