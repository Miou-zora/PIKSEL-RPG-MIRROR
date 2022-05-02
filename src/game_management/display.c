/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display
*/

#include "struct_var.h"

void display(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->enemy->animator_standing->sprite_data->sprite, NULL);
    sfRenderWindow_display(game->window);
}