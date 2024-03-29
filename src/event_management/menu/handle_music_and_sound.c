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
    sfRectangleShape_setPosition(
    game->background->menu->settings_rectangles[0],
    game->background->menu->rectangles_positions[0]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[0],
    game->background->menu->rectangles_sizes[0]);
    game->background->menu->sound = true;
    sfSound_setVolume(game->sound_music->damage, 100);
    sfSound_setVolume(game->sound_music->teleport, 100);
    sfSound_setVolume(game->sound_music->terry, 100);
}

void sound_off(game_t *game)
{
    sfRectangleShape_setPosition(
    game->background->menu->settings_rectangles[0],
    game->background->menu->rectangles_positions[1]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[0],
    game->background->menu->rectangles_sizes[1]);
    game->background->menu->sound = false;
    sfSound_setVolume(game->sound_music->damage, 0);
    sfSound_setVolume(game->sound_music->terry, 0);
    sfSound_setVolume(game->sound_music->teleport, 0);
}

void music_on(game_t *game)
{
    sfRectangleShape_setPosition(
    game->background->menu->settings_rectangles[1],
    game->background->menu->rectangles_positions[2]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[1],
    game->background->menu->rectangles_sizes[2]);
    game->background->menu->music = true;
    sfMusic_setVolume(game->sound_music->music, 100);
}

void music_off(game_t *game)
{
    sfRectangleShape_setPosition(
    game->background->menu->settings_rectangles[1],
    game->background->menu->rectangles_positions[3]);
    sfRectangleShape_setSize(game->background->menu->settings_rectangles[1],
    game->background->menu->rectangles_sizes[3]);
    game->background->menu->music = false;
    sfMusic_setVolume(game->sound_music->music, 0);
}