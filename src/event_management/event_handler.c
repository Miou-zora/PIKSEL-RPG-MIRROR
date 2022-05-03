/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** event_handler
*/

#include "struct_var.h"
#include "my.h"

int event_handler(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (game->background->scene_background == MENU)
            handle_menu_events(game);
        if (game->background->scene_background == SETTINGS)
            handle_settings_events(game);
        manage_key(game);
    }
    return (0);
}