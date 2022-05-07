/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_settings_events
*/

#include "struct_var.h"
#include "my.h"

int find_which_setting(game_t *game)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f rect_pos_left = {0, 0};
    sfVector2f rect_pos_right = {0, 0};
    for (int i = 0; i < 9; i++) {
        rect_pos_left = game->background->menu->rectangles_positions[i];
        rect_pos_right.x =
        rect_pos_left.x + game->background->menu->rectangles_sizes[i].x;
        rect_pos_right.y =
        rect_pos_left.y + game->background->menu->rectangles_sizes[i].y;
        if (mouse_position.x >= rect_pos_left.x &&
        mouse_position.x <= rect_pos_right.x &&
        mouse_position.y >= rect_pos_left.y &&
        mouse_position.y <= rect_pos_right.y)
            return (i);
    }
    return (-1);
}

void come_back_to_menu(game_t *game)
{
    game->background->menu->sprite = load_sprite_data("assets/menu/menu.png");
    sfSprite_setPosition(game->background->menu->sprite->sprite,
    (sfVector2f){0, 0});
    sfSprite_setScale(game->background->menu->sprite->sprite,
    (sfVector2f){8, 8});
    game->background->scene_background = MENU;
}

void handle_settings_events(game_t *game)
{
    int which_setting = -1;
    void(*settings_functions[8])(game_t *) = {sound_on, sound_off, music_on,
    music_off, set_fps_30, set_fps_60, set_fps_120, come_back_to_menu};
    if (game->event.type == sfEvtMouseButtonPressed) {
        which_setting = find_which_setting(game);
        if (which_setting != -1) {
            settings_functions[which_setting](game);
        }
    }
}