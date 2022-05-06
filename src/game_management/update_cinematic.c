/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_cinematic
*/

#include "struct_var.h"
#include "my.h"

void clock_cine_text(cinematic_t **cinematic)
{
    drain_clock_data((*cinematic)->text_zone->text_clock);
    while (update_clock_data((*cinematic)->text_zone->text_clock)) {
        if ((*cinematic)->anim_enemy_run->sprite_data->pos.x >=
        (*cinematic)->anim_player_walk->sprite_data->pos.x) {
            display_one_more_char(&((*cinematic)->text_zone));
        }
    }
}