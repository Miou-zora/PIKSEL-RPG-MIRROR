/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display
*/

#include "struct_var.h"
#include "my.h"

void display_background(game_t *game)
{
    if (game->background->scene_background == ROOM) {
        sfRenderWindow_drawSprite(game->window,
        game->background->bedroom->sprite->sprite, NULL);
    }
}

void display_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->background->menu->sprite->sprite , NULL);
    if (game->background->menu->settings_rectangles != NULL) {
        for (int i = 0; i < 3; i++) {
            sfRenderWindow_drawRectangleShape(game->window,
            game->background->menu->settings_rectangles[i], NULL);
        }
    }
}

void display(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    display_menu(game);
    display_background(game);
    sfRenderWindow_display(game->window);
}