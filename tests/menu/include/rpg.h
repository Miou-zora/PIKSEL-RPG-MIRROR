/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg
*/

#pragma once

#include "../../../lib/my/include/my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct_var.h"

void display(scene_t *scene, dialogues_t *dialogue);
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
int initialize_dialogues(dialogues_t *dialogues);

/************************set event fonctions*********************************/

int change_menu(sfEvent *event, scene_t *scene,
settings_t **settings, dialogues_t **dialogue);
void handle_settings(scene_t **scene, sfEvent *event, settings_t *settings);
void handle_fps(settings_t *settings, sfEvent *event);
void handle_sound(settings_t *settings, sfEvent *event);
void handle_music(settings_t *settings, sfEvent *event);
void handle_quit(scene_t *scene);
int go_to_good_menu(scene_t *scene,
settings_t *settings_struct, dialogues_t **dialogue);
void analyse_event(sfEvent event, game_t *game);

/**************************free functions************************************/

int free_scene(scene_t *scene);
void free_game(scene_t *scene, settings_t *settings, clock_data_t *clock);
void free_settings(settings_infos_t *settings);

/************************text zone functions*********************************/

int create_text_zone(text_zone_t **text_zone, char *text_string);
void display_text_zone(sfRenderWindow *window, text_zone_t *text_zone);
void display_one_more_char(text_zone_t **text_zone);
void free_text_zone(text_zone_t *text_zone);

/*************************dialogue functions*********************************/

int create_dialogue_list(dialogues_t **dialogue);
int create_dialogue_bubble(dialogues_t **bubble, char *string);