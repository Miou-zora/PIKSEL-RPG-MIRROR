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
