/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_game
*/

#include "struct_var.h"
#include "my.h"

bool init_characters_and_cinematic(game_t *game)
{
    if (init_cinematic(&(game->cinematic)) == true)
        return (true);
    if (init_player(game->player))
        return (true);
    if (init_enemy(game))
        return (true);
    if (init_npc(game->npc))
        return (true);
    return (false);
}

bool init_game(game_t *game)
{
    if (init_back(game->background))
        return (true);
    if (init_inventory(&game->player->inventory))
        return (true);
    if (init_characters_and_cinematic(game))
        return (true);
    if (init_sound(&game->sound_music))
        return (true);
    return (false);
}

bool fill_game(game_t *game)
{
    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "Piksel RPG", sfClose, NULL);
    if (game->window == NULL)
        return (true);
    game->is_dead = false;
    game->background = my_calloc(1, sizeof(background_t));
    game->player = my_calloc(1, sizeof(player_t));
    if (game->background == NULL)
        return (true);
    if (initialize_menu(&(game->background->menu)) == true)
        return (true);
    init_game(game);
    return (false);
}

bool initialize_game(game_t **game)
{
    srand(0);
    if (game == NULL)
        return (true);
    (*game) = my_calloc(1, sizeof(*(*game)));
    if ((*game) == NULL)
        return (true);
    if (fill_game(*game) == true) {
        return (true);
    }
    return (false);
}
