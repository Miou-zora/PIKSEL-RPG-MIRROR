/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update
*/

#include "struct_var.h"
#include "my.h"

void move_player_walk(player_t *player, game_t *game)
{
    manage_up(game);
    manage_down(game);
    if (player->move_up == true && player->player_mode == 1)
        player->pos.y -= 7.5;
    if (player->move_down == true && player->player_mode == 1)
        player->pos.y += 7.5;
    if (player->move_right == true && player->player_mode == 1)
        move_background_right(game, 1);
    if (player->move_left == true && player->player_mode == 1)
        move_background_left(game, 1);
}

void move_player_run(player_t *player, game_t *game)
{
    if (player->move_up == true && player->player_mode == 2)
        player->pos.y -= 15;
    if (player->move_down == true && player->player_mode == 2)
        player->pos.y += 15;
    if (player->move_left == true && player->player_mode == 2)
        move_background_left(game, 2);
    if (player->move_right == true && player->player_mode == 2)
        move_background_right(game, 2);
}


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

void update_position(player_t *player)
{
    sfSprite_setPosition(player->run->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->walk->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->iddle->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->sword->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->punch->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->gun->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->spear->sprite_data->sprite, player->pos);
}

void clock_player(player_t *player, game_t *game)
{
    move_player_walk(player, game);
    move_player_run(player, game);
    update_position(player);
}

void clock_animation_player(player_t *player)
{
    if (detect_if_key_pressed(player) == 1)
        player_animation_iddle(player);
    if (player->player_mode == 1 && detect_if_key_pressed(player) == 0)
        player_animation_walk(player);
    if (player->player_mode == 2 && detect_if_key_pressed(player) == 0)
        player_animation_run(player);
}


void called_clock_player(player_t *player, game_t *game)
{
    clock_player(player, game);
    clock_animation_player(player);
}

void update(game_t *game)
{
    if (game->background->menu->how_to_play_mode == true)
        drain_clock_data(game->background->menu->how_to_play->text_clock);
    while (game->background->menu->how_to_play_mode == true &&
    update_clock_data(game->background->menu->how_to_play->text_clock)) {
        drain_clock_data(game->background->menu->how_to_play->text_clock);
        if (display_one_more_char(&game->background->menu->how_to_play)
        == false) {
            game->background->menu->how_to_play_mode = false;
        }
    }
    update_npc(game);
    update_how_to_play(game->background->menu);
    called_clock_player(game->player, game);
    update_position(game->player);
}
