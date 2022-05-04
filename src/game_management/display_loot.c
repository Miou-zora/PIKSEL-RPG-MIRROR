/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_loot
*/

#include "struct_var.h"
#include "my.h"

void display_loot(game_t *game)
{
    if (game->background->loot != NULL) {
        for (int i = 0; (game->background->loot[i]->armor_or_weapon == 0 ||
        game->background->loot[i]->armor_or_weapon == 1) && i < 9; i++) {
            if (game->background->loot[i]->armor_or_weapon == 0)
                sfRenderWindow_drawSprite(game->window,
                game->background->loot[i]->armor->sprite_data->sprite, NULL);
            if (game->background->loot[i]->armor_or_weapon == 1)
                sfRenderWindow_drawSprite(game->window,
                game->background->loot[i]->weapon->sprite_data->sprite, NULL);
        }
    }
}