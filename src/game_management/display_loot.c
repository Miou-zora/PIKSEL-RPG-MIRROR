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
        if (game->background->loot->armor_or_weapon == 0)
            sfRenderWindow_drawSprite(game->window,
            game->background->loot->armor->sprite_data->sprite, NULL);
        if (game->background->loot->armor_or_weapon == 1)
            sfRenderWindow_drawSprite(game->window,
            game->background->loot->weapon->sprite_data->sprite, NULL);
    }
}