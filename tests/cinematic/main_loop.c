/*
** EPITECH PROJECT, 2022
** main_loop
** File description:
** main_loop
*/

#include "struct_var.h"
#include <stdlib.h>

void my_rpg_player(void)
{
    cinematic_t *cinematic = malloc(sizeof(cinematic_t));
    animator_t *animator_player_walk = malloc(sizeof(animator_t));
    animator_t *animator_enemy_run = malloc(sizeof(animator_t));
    sprite_data_t *sprite_data_player_walk = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_enemy_run = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_city = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_light = malloc(sizeof(sprite_data_t));
    sfVideoMode mode = {1920, 1080, 32};

    cinematic->window = sfRenderWindow_create(mode, "PIKSEL", sfClose | sfResize, NULL);
    cinematic->player_walk = animator_player_walk;
    cinematic->player_walk->sprite_data = sprite_data_player_walk;
    cinematic->enemy_run = animator_enemy_run;
    cinematic->enemy_run->sprite_data = sprite_data_enemy_run;

    cinematic->city = sprite_data_city;
    cinematic->light = sprite_data_light;

    create_sprites_cinematic(cinematic);
    while (sfRenderWindow_isOpen(cinematic->window)) {
        while (sfRenderWindow_pollEvent(cinematic->window, &cinematic->event))
            analyse_events(cinematic);
        display_sprite_cinematic(cinematic);
        sfRenderWindow_display(cinematic->window);
        sfRenderWindow_clear(cinematic->window, sfBlack);
    }
}

int main(void)
{
    my_rpg_player();
    return (0);
}