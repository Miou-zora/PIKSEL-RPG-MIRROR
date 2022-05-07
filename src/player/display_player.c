/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** display_player
*/

#include "my.h"
#include "struct_var.h"

int detect_if_key_pressed(player_t *player)
{
    if (player->move_up == false && player->move_down == false &&
    player->move_left == false && player->move_right == false)
        return (1);
    return (0);
}

void display_move_player(player_t *player, game_t *game)
{
    if (detect_if_key_pressed(player) == 1) {
        sfRenderWindow_drawSprite(game->window,
        player->iddle->sprite_data->sprite, NULL);
    }
    if (player->player_mode == 1 && detect_if_key_pressed(player) == 0) {
        sfRenderWindow_drawSprite(game->window,
        player->walk->sprite_data->sprite, NULL);
    }
    if (player->player_mode == 2 && detect_if_key_pressed(player) == 0) {
        sfRenderWindow_drawSprite(game->window,
        player->run->sprite_data->sprite, NULL);
    }
}

void display_attack_player(player_t *player, game_t *game)
{
    if (player->weapon == 1)
        sfRenderWindow_drawSprite(game->window,
        player->sword->sprite_data->sprite, NULL);
    if (player->weapon == 2)
        sfRenderWindow_drawSprite(game->window,
        player->spear->sprite_data->sprite, NULL);
    if (player->weapon == 3)
        sfRenderWindow_drawSprite(game->window,
        player->punch->sprite_data->sprite, NULL);
    if (player->weapon == 4)
        sfRenderWindow_drawSprite(game->window,
        player->gun->sprite_data->sprite, NULL);
}

void display_player_sprites(player_t *player, game_t *game)
{
    if (game->background->scene_background != MENU &&
    game->background->scene_background != SETTINGS) {
        if (player->attack == false)
            display_move_player(player, game);
        if (player->attack == true)
            display_attack_player(player, game);
    }
}