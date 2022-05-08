/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** spawn_random_loot
*/

#include "struct_var.h"
#include "my.h"

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

    for (; loot[which_loot]->armor_or_weapon < 2
    && which_loot < 9; which_loot++);
    if (which_loot < 9) {
        loot[which_loot] = malloc(sizeof(loot_t));
        my_printf("malloc loot\n");
        loot[which_loot]->position = pos;
        loot[which_loot]->disparition_clock = create_clock_data();
        set_framerate_clock_data(loot[which_loot]->disparition_clock, 15);
        set_armor_or_weapon(&(loot[which_loot]), colors, pos);
    }
}