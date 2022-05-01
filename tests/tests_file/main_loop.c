/*
** EPITECH PROJECT, 2022
** test_file_player
** File description:
** test_file_player
*/

#include "struct_var.h"
#include "rpg.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int my_rpg(void)
{
    player_t *player = malloc(sizeof(player_t));
    animator_t *animator_iddle = malloc(sizeof(animator_t));
    animator_t *animator_walk = malloc(sizeof(animator_t));
    animator_t *animator_run = malloc(sizeof(animator_t));
    animator_t *animator_sword = malloc(sizeof(animator_t));
    animator_t *animator_gun = malloc(sizeof(animator_t));
    animator_t *animator_spear = malloc(sizeof(animator_t));
    animator_t *animator_punch = malloc(sizeof(animator_t));
    sprite_data_t *sprite_data_iddle = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_walk = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_run = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_sword = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_gun = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_spear = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_punch = malloc(sizeof(sprite_data_t));
    clock_player_t *struct_clock_player = malloc(sizeof(clock_player_t));
    clock_player_t *struct_clock_animator = malloc(sizeof(clock_player_t));
    clock_player_t *struct_clock_sword = malloc(sizeof(clock_player_t));
    clock_player_t *struct_clock_punch = malloc(sizeof(clock_player_t));
    clock_player_t *struct_clock_spear = malloc(sizeof(clock_player_t));
    clock_player_t *struct_clock_gun = malloc(sizeof(clock_player_t));
    sfVideoMode mode = {1920, 1080, 32};

    // Move

    player->window = sfRenderWindow_create(mode, "PIKSEL", sfClose | sfResize, NULL);
    player->iddle = animator_iddle;
    player->iddle->sprite_data = sprite_data_iddle;
    player->walk = animator_walk;
    player->walk->sprite_data = sprite_data_walk;
    player->run = animator_run;
    player->run->sprite_data = sprite_data_run;

    player->player = struct_clock_player;
    player->anim = struct_clock_animator;
    player->c_sword = struct_clock_sword;
    player->c_punch = struct_clock_punch;
    player->c_gun = struct_clock_gun;
    player->c_spear = struct_clock_spear;

    // Attack

    player->sword = animator_sword;
    player->sword->sprite_data = sprite_data_sword;
    player->gun = animator_gun;
    player->gun->sprite_data = sprite_data_gun;
    player->spear = animator_spear;
    player->spear->sprite_data = sprite_data_spear;
    player->punch = animator_punch;
    player->punch->sprite_data = sprite_data_punch;

    player->player->clock = sfClock_create();
    player->anim->clock = sfClock_create();
    player->c_sword->clock = sfClock_create();
    player->c_spear->clock = sfClock_create();
    player->c_gun->clock = sfClock_create();
    player->c_punch->clock = sfClock_create();
    player->player_walk = false;
    player->player_run = false;
    player->player_mode = 1;
    player->pos = (sfVector2f){0, 0};
    player->weapon = 1;
    player->attack = false;

    create_sprite_player(player);
    while (sfRenderWindow_isOpen(player->window)) {
        while (sfRenderWindow_pollEvent(player->window, &player->event))
            analyse_events(player);
        called_clock(player);
        detect_if_key_pressed(player);
        update_position(player);
        display_player_sprites(player);
        sfRenderWindow_display(player->window);
        sfRenderWindow_clear(player->window, sfBlack);
    }
    return (0);
}

int main()
{
    my_rpg();
    return (0);
}
