/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_music_and_sound
*/

#include "struct_var.h"
#include "my.h"

void sound_on(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    sfRectangleShape_setPosition(game->background->menu->settings_rectangles[0],
    game->background->menu->rectangles_positions[0]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[0],
    game->background->menu->rectangles_sizes[0]);
    my_putstr("sound_on");
}

void sound_off(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    sfRectangleShape_setPosition(game->background->menu->settings_rectangles[0],
    game->background->menu->rectangles_positions[1]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[0],
    game->background->menu->rectangles_sizes[1]);
    my_putstr("sound_off");
}

void music_on(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    sfRectangleShape_setPosition(game->background->menu->settings_rectangles[1],
    game->background->menu->rectangles_positions[2]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[1],
    game->background->menu->rectangles_sizes[2]);
    my_putstr("music_on");
}

void music_off(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    sfRectangleShape_setPosition(game->background->menu->settings_rectangles[1],
    game->background->menu->rectangles_positions[3]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[1],
    game->background->menu->rectangles_sizes[3]);
    my_putstr("music_off");
}