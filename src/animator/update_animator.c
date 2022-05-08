/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** update_animator
*/

#include "struct_var.h"

void update_animator(animator_t *animator, game_t *game)
{
    if (animator == NULL)
        return;
    drain_clock_data(animator->clock_data);
    if (update_clock_data(animator->clock_data)) {
        increment_animator_image_pos(animator);
    }
    refresh_animator(animator);
    if (animator->sprite_data != NULL
    && game->background->menu->pause->display_pause == false)
        sfSprite_setTextureRect(animator->sprite_data->sprite,
        animator->sprite_data->rect);
}
