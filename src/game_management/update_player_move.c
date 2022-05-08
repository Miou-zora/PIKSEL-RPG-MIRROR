/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update
*/

#include "struct_var.h"
#include "my.h"

void player_animation_run(player_t *player)
{
    player->run->sprite_data->rect.left += 48;
    if (player->run->sprite_data->rect.left == 288)
        player->run->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->run->sprite_data->sprite);
    sfSprite_setTextureRect(player->run->sprite_data->sprite,
    player->run->sprite_data->rect);
}

void player_animation_walk(player_t *player)
{
    player->walk->sprite_data->rect.left += 48;
    if (player->walk->sprite_data->rect.left == 288)
        player->walk->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->walk->sprite_data->sprite);
    sfSprite_setTextureRect(player->walk->sprite_data->sprite,
    player->walk->sprite_data->rect);
}

void player_animation_iddle(player_t *player)
{
    player->iddle->sprite_data->rect.left += 48;
    if (player->iddle->sprite_data->rect.left == 288)
        player->iddle->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->iddle->sprite_data->sprite);
    sfSprite_setTextureRect(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->rect);
}

void move_player_walk(player_t *player, game_t *game)
{
    manage_down(game);
    manage_up(game);
    if (player->move_up == true && player->player_mode == 1)
        player->pos.y -= 7.5;
    if (player->move_down == true && player->player_mode == 1)
        player->pos.y += 7.5;
    if (player->move_right == true && player->player_mode == 1
    && game->background->menu->pause->display_pause == false)
        move_background_right(game, 1);
    if (player->move_left == true && player->player_mode == 1
    && game->background->menu->pause->display_pause == false)
        move_background_left(game, 1);
}

void move_player_run(player_t *player, game_t *game)
{
    manage_down(game);
    manage_up(game);
    if (player->move_up == true && player->player_mode == 2)
        player->pos.y -= 15;
    if (player->move_down == true && player->player_mode == 2)
        player->pos.y += 15;
    if (player->move_left == true && player->player_mode == 2
    && game->background->menu->pause->display_pause == false)
        move_background_left(game, 2);
    if (player->move_right == true && player->player_mode == 2
    && game->background->menu->pause->display_pause == false)
        move_background_right(game, 2);
}