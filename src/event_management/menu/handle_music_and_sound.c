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
    my_putstr("sound_on");
}

void sound_off(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    my_putstr("sound_off");
}

void music_on(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    my_putstr("music_on");
}

void music_off(game_t *game)
{
    my_put_nbr(game->background->menu->rectangles_sizes->x);
    my_putstr("music_off");
}