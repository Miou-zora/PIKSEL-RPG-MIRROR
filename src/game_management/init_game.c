/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_game
*/

#include "struct_var.h"
#include "my.h"

bool initialize_game(game_t **game)
{
    if (game == NULL)
        return (true);
    (*game) = my_calloc(1, sizeof(*game));
    if ((*game) == NULL)
        return (true);
    (*game)->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "Piksel RPG", sfClose, NULL);
    if ((*game)->window == NULL)
        return (true);
    return (false);
}