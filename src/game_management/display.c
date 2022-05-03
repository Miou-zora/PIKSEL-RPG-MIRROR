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
    if (game->background->scene_background == SETTINGS) {
        for (int i = 0; i < 3; i++) {
            sfRenderWindow_drawRectangleShape(game->window,
            game->background->menu->settings_rectangles[i], NULL);
        }
    }
    if (game->background->menu->how_to_play_mode == true) {
        sfRenderWindow_drawSprite(game->window,
        game->background->menu->how_to_play->text_zone_sprite->sprite, NULL);
        sfRenderWindow_drawText(game->window,
        game->background->menu->how_to_play->text, NULL);
    }
}

void display(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->background->scene_background == MENU ||
    game->background->scene_background == SETTINGS)
        display_menu(game);
    display_background(game);
    display_player_sprites(game->player, game);
    sfRenderWindow_display(game->window);
}