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
        else if (game->event.type == sfEvtMouseButtonPressed) {
            go_to_good_menu(sfMouse_getPositionRenderWindow(game->window),
            game);
        }
    }
    return (0);
}