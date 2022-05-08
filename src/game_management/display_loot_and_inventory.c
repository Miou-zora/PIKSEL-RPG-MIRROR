/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_loot
*/

#include "struct_var.h"
#include "my.h"

void display_each_loot(game_t *game)
{
    for (int i = 0;
    game->background->loot[i]->armor_or_weapon != 2 && i < 9; i++) {
        if (game->background->loot[i]->armor_or_weapon == 3)
            continue;
        if (game->background->loot[i]->armor_or_weapon == 0) {
            sfRenderWindow_drawSprite(game->window,
            game->background->loot[i]->armor->sprite_data->sprite, NULL);
        }
        if (game->background->loot[i]->armor_or_weapon == 1) {
            sfRenderWindow_drawSprite(game->window,
            game->background->loot[i]->weapon->sprite_data->sprite, NULL);
        }
    }
}

void display_loot(game_t *game)
{
    if (game->background->loot != NULL) {
        display_each_loot(game);
    }
}

void display_armors(game_t *game)
{
    if (game->player->inventory->boots != NULL) {
        sfRenderWindow_drawSprite(game->window,
        game->player->inventory->boots->sprite_data->sprite, NULL);
    }
    if (game->player->inventory->chestplate != NULL) {
        sfRenderWindow_drawSprite(game->window,
        game->player->inventory->chestplate->sprite_data->sprite, NULL);
    }
    if (game->player->inventory->pant != NULL) {
        sfRenderWindow_drawSprite(game->window,
        game->player->inventory->pant->sprite_data->sprite, NULL);
    }
    (game->player->inventory->helmet != NULL) ?
    sfRenderWindow_drawSprite(game->window,
    game->player->inventory->helmet->sprite_data->sprite, NULL) : 0;
}

void display_inventory(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->player->inventory->sprite_data->sprite, NULL);
    if (game->player->inventory->weapon != NULL) {
        sfRenderWindow_drawSprite(game->window,
        game->player->inventory->weapon->sprite_data->sprite, NULL);
    }
    display_armors(game);
}
