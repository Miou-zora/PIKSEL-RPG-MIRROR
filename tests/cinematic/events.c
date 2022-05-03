/*
** EPITECH PROJECT, 2022
** events
** File description:
** events
*/

#include "struct_var.h"
#include <stdio.h>
#include "my.h"

void check_pos_cinematic(cinematic_t *cinematic)
{
    sfVector2f pos_player = sfSprite_getPosition(cinematic->anim_player_walk->sprite_data->sprite);
    sfVector2f pos_enemy = sfSprite_getPosition(cinematic->anim_enemy_run->sprite_data->sprite);

    if (pos_enemy.x >= 500) {
        cinematic->walk = false;
        cinematic->run = false;
    }
    my_printf("P: %i | E: %i\n", (int)pos_player.x, (int)pos_enemy.x);
}

void analyse_events(cinematic_t *cinematic)
{
    if (cinematic->event.type == sfEvtClosed)
        sfRenderWindow_close(cinematic->window);
    // check_pos_cinematic(cinematic);
}