/*
** EPITECH PROJECT, 2022
** main_loop
** File description:
** main_loop
*/

#include "struct_var.h"
#include <stdlib.h>
#include "my.h"

void my_rpg_player(void)
{
    cinematic_t *cinematic = malloc(sizeof(cinematic_t));
    animator_t *animator_player_walk = malloc(sizeof(animator_t));
    animator_t *animator_enemy_run = malloc(sizeof(animator_t));
    sprite_data_t *sprite_data_player_walk = load_sprite_data("assets/player/Stick walk.png");
    sprite_data_t *sprite_data_enemy_run = load_sprite_data("assets/player/Stick run enemy(1).png");
    sprite_data_t *sprite_data_city = load_sprite_data("assets/background/city.png");
    sprite_data_t *sprite_data_light = load_sprite_data("assets/background/Lampadaire.png");
    sfVideoMode mode = {1920, 1080, 32};

    cinematic->window = sfRenderWindow_create(mode, "PIKSEL", sfClose | sfResize, NULL);

    cinematic->anim_player_walk = animator_player_walk;
    cinematic->anim_player_walk->sprite_data = sprite_data_player_walk;
    cinematic->anim_player_walk->clock_data = create_clock_data();
    set_framerate_clock_data(cinematic->anim_player_walk->clock_data, 1000000 / 15);

    cinematic->anim_enemy_run = animator_enemy_run;
    cinematic->anim_enemy_run->sprite_data = sprite_data_enemy_run;
    cinematic->anim_enemy_run->clock_data = create_clock_data();
    set_framerate_clock_data(cinematic->anim_enemy_run->clock_data, 1000000 / 15);

    cinematic->clock_move_player = create_clock_data();
    set_framerate_clock_data(cinematic->clock_move_player, 1000000 / 60);

    cinematic->clock_move_enemy = create_clock_data();
    set_framerate_clock_data(cinematic->clock_move_enemy, 1000000 / 60);

    cinematic->city = sprite_data_city;
    cinematic->light = sprite_data_light;

    cinematic->walk = true;
    cinematic->run = true;
    create_sprites_cinematic(cinematic);
    while (sfRenderWindow_isOpen(cinematic->window)) {
        while (sfRenderWindow_pollEvent(cinematic->window, &cinematic->event))
            analyse_events(cinematic);
        call_clock_cine(cinematic);
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