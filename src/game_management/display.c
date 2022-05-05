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
        //display_npc(game);
        display_hitbox(game->player->hitbox, game->window, game->player->hitbox_color);
        display_player_sprites(game->player, game);
    }
    if (game->background->scene_background == CITY) {
        sfRenderWindow_drawSprite(game->window,
        game->background->town[0]->sprite->sprite, NULL);
        display_player_sprites(game->player, game);
        //display_npc(game);
        sfRenderWindow_drawSprite(game->window,
        game->background->town[1]->sprite->sprite, NULL);
    }
    if (game->background->scene_background == FOREST) {
        sfRenderWindow_drawSprite(game->window,
        game->background->forest[0]->sprite->sprite, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->background->forest[1]->sprite->sprite, NULL);
        //display_npc(game);
        display_player_sprites(game->player, game);
    }
    if (game->background->scene_background == LABO) {
        sfRenderWindow_drawSprite(game->window,
        game->background->laboratory->sprite->sprite, NULL);
        //display_npc(game);
        display_player_sprites(game->player, game);
    }
    if (game->background->scene_background != MENU
    && game->background->scene_background != SETTINGS
    && game->background->scene_background != CINEMATIC) {
        sfRenderWindow_drawSprite(game->window,
        game->player->stat->top_bar->sprite, NULL);
        display_stats(game);
    }
    display_loot(game);
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
    if (game->player->inventory->display_inventory == true)
        display_inventory(game);
    if (game->background->scene_background == CINEMATIC) {
        display_sprite_cinematic(game);
    }
    sfRenderWindow_display(game->window);
}
