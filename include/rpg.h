/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg
*/

#pragma once

#include "../lib/my/include/my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct_var.h"

/***********************init fonctions player********************************/

void clock_animation_player(player_t *player);
void clock_player(player_t *player);
void create_sprite_player(player_t *player);
void display(player_t *player);
int detect_if_key_pressed(player_t *player);
void analyse_events(player_t *player);
void move_player_walk(player_t *player);
void move_player_run(player_t *player);
void player_animation_iddle(player_t *player);
void player_animation_walk(player_t *player);
void player_animation_run(player_t *player);
void update_position(player_t *player);
