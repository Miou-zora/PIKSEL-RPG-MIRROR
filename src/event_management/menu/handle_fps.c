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
    my_putstr("fps 30");
}

void set_fps_60(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    my_putstr("fps 60");
}

void set_fps_120(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    my_putstr("fps 120");
}