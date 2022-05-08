/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_background
*/

#include "struct_var.h"

void display_room(game_t *game)
{
    if (game->background->scene_background == ROOM) {
        sfRenderWindow_drawSprite(game->window,
        game->background->bedroom->sprite->sprite, NULL);
        display_npc(game);
        display_loot(game);
        display_hitbox(game->player->hitbox, game->window,
        game->player->hitbox_color);
        display_player_sprites(game->player, game);
        if (game->background->menu->pause->display_pause_sprite == true)
            display_pause(game);
    }
}

void display_city(game_t *game)
{
    if (game->background->scene_background == CITY) {
        sfRenderWindow_drawSprite(game->window,
        game->background->town[0]->sprite->sprite, NULL);
        display_npc(game);
        display_loot(game);
        display_enemies_list(&(game->enemies_list), game->window);
        display_player_sprites(game->player, game);
        sfRenderWindow_drawSprite(game->window,
        game->background->town[1]->sprite->sprite, NULL);
        display_text(game);
        if (game->background->menu->pause->display_pause_sprite == true)
            display_pause(game);
    }
}

void display_forest(game_t *game)
{
    if (game->background->scene_background == FOREST) {
        sfRenderWindow_drawSprite(game->window,
        game->background->forest[0]->sprite->sprite, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->background->forest[1]->sprite->sprite, NULL);
        display_npc(game);
        display_loot(game);
        if (game->background->menu->pause->display_pause_sprite == true)
            display_pause(game);
        display_enemies_list(&(game->enemies_list), game->window);
        display_player_sprites(game->player, game);
        display_text(game);
    }
}

void display_labo(game_t *game)
{
    if (game->background->scene_background == LABO) {
        sfRenderWindow_drawSprite(game->window,
        game->background->laboratory->sprite->sprite, NULL);
        display_npc(game);
        display_player_sprites(game->player, game);
        if (game->background->menu->pause->display_pause_sprite == true)
            display_pause(game);
        display_enemies_list(&(game->enemies_list), game->window);
        display_text(game);
    }
}

void display_background(game_t *game)
{
    display_room(game);
    display_city(game);
    display_forest(game);
    display_labo(game);
    if (game->background->scene_background != MENU
    && game->background->scene_background != SETTINGS
    && game->background->scene_background != CINEMATIC) {
        sfRenderWindow_drawSprite(game->window,
        game->player->stat->top_bar->sprite, NULL);
        display_stats(game);
    }
}
