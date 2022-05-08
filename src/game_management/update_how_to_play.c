/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_how_to_play
*/

#include "struct_var.h"

void update_position(player_t *player)
{
    player->hitbox.left = player->pos.x + 100;
    player->hitbox.top = player->pos.y + 280;
    sfSprite_setPosition(player->run->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->walk->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->iddle->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->sword->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->punch->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->gun->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->spear->sprite_data->sprite, player->pos);
}

void update_direction_attack(game_t *game)
{
    if (game->player->direction == false) {
        game->player->gun->sprite_data->rect.top = 48;
        game->player->sword->sprite_data->rect.top = 48;
        game->player->spear->sprite_data->rect.top = 48;
        game->player->punch->sprite_data->rect.top = 48;
    } else {
        game->player->gun->sprite_data->rect.top = 0;
        game->player->sword->sprite_data->rect.top = 0;
        game->player->spear->sprite_data->rect.top = 0;
        game->player->punch->sprite_data->rect.top = 0;
    }
    sfSprite_setTextureRect(game->player->run->sprite_data->sprite,
    game->player->gun->sprite_data->rect);
    sfSprite_setTextureRect(game->player->run->sprite_data->sprite,
    game->player->punch->sprite_data->rect);
    sfSprite_setTextureRect(game->player->run->sprite_data->sprite,
    game->player->spear->sprite_data->rect);
    sfSprite_setTextureRect(game->player->run->sprite_data->sprite,
    game->player->sword->sprite_data->rect);
}

void update_how_to_play(menu_t *menu)
{
    if (menu->how_to_play_mode == true)
        drain_clock_data(menu->how_to_play->text_clock);
    while (menu->how_to_play_mode == true &&
    update_clock_data(menu->how_to_play->text_clock)) {
        if (display_one_more_char(&menu->how_to_play)
        == false) {
            menu->how_to_play_mode = false;
        }
    }
}
