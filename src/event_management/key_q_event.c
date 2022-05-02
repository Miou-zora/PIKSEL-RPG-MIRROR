/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

int manage_key_q(game_t *game)
{
    if (game->event.key.code == sfKeyQ) {
        if (game->background->bedroom->sprite->rect.left > 0
        && game->background->scene_background == ROOM)
            game->background->bedroom->sprite->rect.left -= 5;
        sfSprite_setTextureRect(game->background->bedroom->sprite->sprite ,
        game->background->bedroom->sprite->rect);
    }
    return (0);
}