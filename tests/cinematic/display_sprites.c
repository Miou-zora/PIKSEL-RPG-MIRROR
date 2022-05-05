/*
** EPITECH PROJECT, 2022
** display_sprites
** File description:
** disply_sprites
*/

#include "struct_var.h"

void display_sprite_cinematic(cinematic_t *cinematic)
{
    sfRenderWindow_drawSprite(cinematic->window,
    cinematic->city->sprite, NULL);
    sfRenderWindow_drawSprite(cinematic->window,
    cinematic->anim_player_walk->sprite_data->sprite, NULL);
    sfRenderWindow_drawSprite(cinematic->window,
    cinematic->anim_enemy_run->sprite_data->sprite, NULL);
    sfRenderWindow_drawSprite(cinematic->window,
    cinematic->light->sprite, NULL);
    if (cinematic->anim_enemy_run->sprite_data->pos.x >= cinematic->anim_player_walk->sprite_data->pos.x)
        display_text_zone(cinematic->window, cinematic->text_zone);
    sfRenderWindow_drawSprite(cinematic->window,
    cinematic->skip_button->sprite, NULL);
}