/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_menu_events
*/

#include "struct_var.h"

void handle_menu_events(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        go_to_good_menu(sfMouse_getPositionRenderWindow(game->window), game);
    }
}