/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_pause
*/

#include "struct_var.h"
#include "my.h"

void display_pause(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->background->menu->pause->back->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->background->menu->pause->sprite->sprite, NULL);
}