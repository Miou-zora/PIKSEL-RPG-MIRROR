/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_cinematic
*/

#include "struct_var.h"

void display_text_zone(sfRenderWindow *window, text_zone_t *text_zone)
{
    sfRenderWindow_drawSprite(window,
    text_zone->text_zone_sprite->sprite, NULL);
    sfRenderWindow_drawText(window, text_zone->text, NULL);
}

void display_sprite_cinematic(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->cinematic->city->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->cinematic->anim_player_walk->sprite_data->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->cinematic->anim_enemy_run->sprite_data->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->cinematic->light->sprite, NULL);
    if (game->cinematic->anim_enemy_run->sprite_data->pos.x >= game->cinematic->anim_player_walk->sprite_data->pos.x)
        display_text_zone(game->window, game->cinematic->text_zone);
    sfRenderWindow_drawSprite(game->window,
    game->cinematic->skip_button->sprite, NULL);
}