/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_cinematic
*/

#include "struct_var.h"
#include "my.h"

void create_sprites_cinematic(cinematic_t *cinematic)
{
    create_sprite_cine_player(cinematic);
    create_sprite_cine_enemy(cinematic);
    create_sprite_cine_city(cinematic);
    create_sprite_cine_light(cinematic);
    create_sprite_skip_button(cinematic);
}

void create_cinematic_player_and_enemy(cinematic_t **cinematic)
{
    animator_t *animator_player_walk = malloc(sizeof(animator_t));
    animator_t *animator_enemy_run = malloc(sizeof(animator_t));
    sprite_data_t *sprite_data_player_walk =
    load_sprite_data("assets/player/stick_walk.png");
    sprite_data_t *sprite_data_enemy_run =
    load_sprite_data("assets/player/stick_run_enemy.png");

    (*cinematic)->anim_player_walk = animator_player_walk;
    (*cinematic)->anim_player_walk->sprite_data = sprite_data_player_walk;
    (*cinematic)->anim_player_walk->clock_data = create_clock_data();
    set_framerate_clock_data((*cinematic)->anim_player_walk->clock_data, 0.1);
    (*cinematic)->anim_enemy_run = animator_enemy_run;
    (*cinematic)->anim_enemy_run->sprite_data = sprite_data_enemy_run;
    (*cinematic)->anim_enemy_run->clock_data = create_clock_data();
    set_framerate_clock_data((*cinematic)->anim_enemy_run->clock_data, 0.1);
    (*cinematic)->clock_move_player = create_clock_data();
    set_framerate_clock_data((*cinematic)->clock_move_player, 0.07);
    (*cinematic)->clock_move_enemy = create_clock_data();
    set_framerate_clock_data((*cinematic)->clock_move_enemy, 0.04);
}

bool init_cinematic(cinematic_t **cinematic)
{
    (*cinematic) = malloc(sizeof(cinematic_t));
    (*cinematic)->text_zone = NULL;
    create_cinematic_player_and_enemy(cinematic);
    (*cinematic)->city = load_sprite_data("assets/background/city.png");
    (*cinematic)->light = load_sprite_data("assets/background/light.png");
    (*cinematic)->skip_button =
    load_sprite_data("assets/cinematic/skip_cine.png");
    (*cinematic)->walk = true;
    (*cinematic)->run = true;
    if (create_text_zone(&(*cinematic)->text_zone,
    "Oh no my groceries! Dirty thief! You'll see what I'm made of !"
    " I'm going to find you !\n\n\n\nPress space to skip") == 84)
        return (true);
    (*cinematic)->text_zone->text_clock = create_clock_data();
    set_framerate_clock_data((*cinematic)->text_zone->text_clock, 0.03);
    create_sprites_cinematic((*cinematic));
    return (false);
}