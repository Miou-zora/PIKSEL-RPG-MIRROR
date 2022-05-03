/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

int manage_key_d(game_t *game)
{
    if (game->event.key.code == sfKeyD) {
        if (game->background->bedroom->sprite->rect.left < 300
        && game->background->scene_background == ROOM)
            game->background->bedroom->sprite->rect.left += 5;
        sfSprite_setTextureRect(game->background->bedroom->sprite->sprite ,
        game->background->bedroom->sprite->rect);
        game->player->move_right = true;
    }
    return (0);
}