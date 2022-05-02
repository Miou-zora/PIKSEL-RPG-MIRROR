/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display
*/

#include "struct_var.h"

void display_background(game_t *game)
{
    if (game->background->scene_background == ROOM) {
        sfRenderWindow_drawSprite(game->window,
        game->background->bedroom->sprite->sprite, NULL);
    }
    
}

void display(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window,
    game->background->menu->sprite->sprite , NULL);
    // display_background(game);
    // sfRenderWindow_drawSprite(game->window,
    // game->enemy->animator_standing->sprite_data->sprite, NULL);
    sfRenderWindow_display(game->window);
}