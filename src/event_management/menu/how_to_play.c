/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** how_to_play
*/

#include "struct_var.h"
#include "my.h"

int how_to_play(game_t *game)
{
    if (initialize_how_to_play(game) == 84)
        return (84);
    game->background->menu->how_to_play_mode = true;
    return (0);
}