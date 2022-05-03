/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_fps
*/

#include "struct_var.h"
#include "my.h"

void set_fps_30(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    sfRectangleShape_setPosition(game->background->menu->settings_rectangles[2],
    game->background->menu->rectangles_positions[4]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[2],
    game->background->menu->rectangles_sizes[4]);
    my_putstr("fps 30");
}

void set_fps_60(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    sfRectangleShape_setPosition(game->background->menu->settings_rectangles[2],
    game->background->menu->rectangles_positions[5]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[2],
    game->background->menu->rectangles_sizes[5]);
    my_putstr("fps 60");
}

void set_fps_120(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    sfRectangleShape_setPosition(game->background->menu->settings_rectangles[2],
    game->background->menu->rectangles_positions[6]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[2],
    game->background->menu->rectangles_sizes[6]);
    my_putstr("fps 120");
}