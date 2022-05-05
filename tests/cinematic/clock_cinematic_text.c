/*
** EPITECH PROJECT, 2022
** clock_cinematic_text
** File description:
** clock_cinematic_text
*/

#include "struct_var.h"

void clock_cine_text(cinematic_t *cinematic)
{
    drain_clock_data(cinematic->text_zone->text_clock);
    while (update_clock_data(cinematic->text_zone->text_clock)) {
        if (cinematic->anim_enemy_run->sprite_data->pos.x >=
        cinematic->anim_player_walk->sprite_data->pos.x) {
            display_one_more_char(&cinematic->text_zone);
            sfClock_restart(cinematic->text_zone->text_clock->clock);
        }
    }
}
