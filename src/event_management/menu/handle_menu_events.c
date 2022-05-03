/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_menu_events
*/

#include "struct_var.h"

void handle_menu_events(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed &&
    game->background->menu->how_to_play_mode == false) {
        go_to_good_menu(sfMouse_getPositionRenderWindow(game->window), game);
    }
    if (game->background->menu->how_to_play_mode == true &&
    sfMouse_isButtonPressed(game->event.mouseButton.button)) {
        game->background->menu->how_to_play->enter_is_pressed = true;
    }
}