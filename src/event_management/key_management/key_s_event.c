/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** key_s_event
*/

#include "struct_var.h"
#include "my.h"

int manage_key_s(game_t *game)
{
    if (game->event.key.code == sfKeyS
    && game->background->menu->pause->display_pause == false
    && game->background->scene_background != MENU
    && game->background->scene_background != SETTINGS
    && game->background->scene_background != CINEMATIC) {
        game->player->move_down = true;
    }
    return (0);
}