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


void display(game_t *game);
void free_all(game_t *game);
int my_rpg(void);
void set_mouse_cursor(game_t *game);

/**************************init fonctions***********************************/

int initialize_var(game_t *game);
int initialize_cursor(game_t *game);
int initialize_game_end(game_t *game);
int initialize_how_to_play(game_t *game);
int initialize_intro(game_t *game);
int initialize_menu(game_t *game);
int initialize_options(game_t *game);
int initialize_pause(game_t *game);
int initialize_window(game_t *game);
int initialize_sound(game_t *game);
int initialize_music(game_t *game);

/************************set event fonctions*********************************/

void analyse_event(game_t *game);