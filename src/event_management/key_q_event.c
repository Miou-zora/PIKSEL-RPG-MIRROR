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
        game->player->move_left = true;
        sfSprite_setOrigin(game->player->walk->sprite_data->sprite,
        (sfVector2f){game->player->walk->size_image.x / 2.f,
        game->player->walk->size_image.y});
        sfSprite_setScale(game->player->walk->sprite_data->sprite,
        (sfVector2f){game->player->walk->sprite_data->scale.x * -1, 
        game->player->walk->sprite_data->scale.y});

    }
    return (0);
}