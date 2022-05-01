/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg
*/

#pragma once

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include "struct_var.h"


/***********************init fonctions player********************************/

void called_clock_player(player_t *player);
void called_clock_player_attack(player_t *player);
void create_sprite_player(player_t *player);
void display_player_sprites(player_t *player);
int detect_if_key_pressed(player_t *player);
void analyse_events(player_t *player);
void move_player_walk(player_t *player);
void move_player_run(player_t *player);
void player_animation_iddle(player_t *player);
void player_animation_walk(player_t *player);
void player_animation_run(player_t *player);
void player_animation_sword(player_t *player);
void player_animation_gun(player_t *player);
void player_animation_punch(player_t *player);
void player_animation_spear(player_t *player);
void update_position(player_t *player);

//void display(scene_t *scene, text_zone_t *text_zone);
void update_clock(clock_data_t *clock);
// void free_all(game_t *game);
int my_rpg(void);
// void set_mouse_cursor(game_t *game);

/**************************init fonctions***********************************/

// int initialize_var(game_t *game);
// int initialize_cursor(game_t *game);
// int initialize_game_end(game_t *game);
// int initialize_how_to_play(game_t *game);
// int initialize_intro(game_t *game);
// int initialize_menu(game_t *game);
// int initialize_options(game_t *game);
// int initialize_pause(game_t *game);
int initialize_window(sfRenderWindow **window);
// int initialize_sound(game_t *game);
// int initialize_music(game_t *game);
int initialize_scene(scene_t **scene, char *zone_name, int nb_of_zones,
bool new_window);
int initialize_sprite_data(sprite_data_t **sprite_data, char *path_to_image,
sfVector2f scale, sfVector2f position);
int initialize_clock(clock_data_t **clock);
int initialize_settings(scene_t **new_scene, scene_t *old_scene);
void initialize_hitbox(selection_zone_t **select_zone,
char *pos_file, int nb_of_zones);
sfVector2f *initialize_positions(char *positions_buffer, int nb_of_zones);
int initialize_settings_values(settings_t **settings, scene_t **scene);
int initialize_game(scene_t **game_scene, scene_t *old_scene);

/************************set event fonctions*********************************/

int change_menu(sfEvent *event, scene_t *scene,
settings_t **settings, text_zone_t **text_zone);
void handle_settings(scene_t **scene, sfEvent *event, settings_t *settings);
void handle_fps(settings_t *settings, sfEvent *event);
void handle_sound(settings_t *settings, sfEvent *event);
void handle_music(settings_t *settings, sfEvent *event);
void handle_quit(scene_t *scene);
int go_to_good_menu(scene_t *scene,
settings_t *settings_struct, text_zone_t **text_zone);
//void analyse_event(sfEvent event, game_t *game);

/**************************free functions************************************/

int free_scene(scene_t *scene);
void free_game(scene_t *scene, settings_t *settings, clock_data_t *clock);
void free_settings(settings_infos_t *settings);

/************************text zone functions*********************************/

void create_text_zone(scene_t **scene,
text_zone_t **text_zone, char *text_string);
void display_text_zone(sfRenderWindow *window, text_zone_t *text_zone);
void display_one_more_char(text_zone_t **text_zone);
void free_text_zone(text_zone_t *text_zone);
