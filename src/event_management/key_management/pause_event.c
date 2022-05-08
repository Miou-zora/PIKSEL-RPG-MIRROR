/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** pause_event
*/

#include "struct_var.h"
#include "my.h"

void resume(game_t *game)
{
    game->background->menu->pause->display_pause = false;
    game->background->menu->pause->display_pause_sprite = false;
}

void leave(game_t *game)
{
    sfRenderWindow_close(game->window);
}

void go_to_menu(game_t *game)
{
    game->background->menu->pause->display_pause = false;
    game->background->menu->pause->display_pause_sprite = false;
    init_game(game);
}

void click_on_buttons_on_pause(game_t *game)
{
    void (*pause_fonctions[3])(game_t *) = {resume, leave, go_to_menu};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f rect_pos;
    sfVector2f rect_size;

    for (int i = 0; i < 3; i++) {
        rect_pos = game->background->menu->pause->rectangles_positions[i];
        rect_size = game->background->menu->pause->rectangles_sizes[i];
        if (mouse_pos.x >= rect_pos.x && mouse_pos.x <= rect_pos.x +
        rect_size.x && mouse_pos.y >= rect_pos.y && mouse_pos.y <=
        rect_pos.y + rect_size.y) {
            pause_fonctions[i](game);
        }
    }
}

void manage_pause(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->event.key.code) == true
    && game->event.key.code == sfKeyEscape
    && game->background->scene_background != MENU
    && game->background->scene_background != SETTINGS
    && game->background->scene_background != CINEMATIC) {
        if (game->background->menu->pause->display_pause == false) {
            game->background->menu->pause->display_pause = true;
            game->background->menu->pause->display_pause_sprite = true;
        } else {
            game->background->menu->pause->display_pause = false;
            game->background->menu->pause->display_pause_sprite = false;
        }
    }
    if (game->background->menu->pause->display_pause_sprite == true &&
    game->event.type == sfEvtMouseButtonPressed) {
        click_on_buttons_on_pause(game);
    }
}