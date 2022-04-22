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

/************************** enum ***********************************/

enum types_armor {HELMET, CHESTPLATE, LEGGINGS, BOOTS};
enum types_bonus_basic {HEALTH, REGENERATION, POWER, ARMOR, SPEED, CHARISMA};

/************************** typedef ***********************************/

typedef struct armor_s armor_t;
typedef struct sprite_data_s sprite_data_t;
typedef struct animator_s animator_t;
typedef struct clock_data_s clock_data_t;

/************************** struct ***********************************/

struct armor_s {
    char *name;
    int id;
    enum types_armor type_armor;
    enum types_bonus_basic type_bonus_basic;
    float rarity;
    int value_bonus;
    sprite_data_t *sprite_data;
};

struct sprite_data_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
};

struct animator_s {
    int number_image;
    sfVector2i actual_image;
    sfVector2i nbr_image_xy;
    sfVector2i size_image;
    sprite_data_t *sprite_data;
    clock_data_t *clock;
};

struct clock_data_s {
    sfClock *clocksfInt64;
    sfInt64 elapsed_time;
    sfTime currElapsedTime;
    int time_between_each_actualization;
};

typedef struct init_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
}init_sprite_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f scale;
    char *str;
} text_t;

typedef struct background_s {
    init_sprite_t *sprite;
    char *name;
}background_t;

typedef struct button_s {
    init_sprite_t *sprite;
    text_t *text;
    int status;
}button_t;

typedef struct sprite_s {
    background_t *background[60];
    button_t *button[60];
    //mob_t *mob[4];
    //map_t *map[5];
    //caracter_t *caracter_pos[5];
    //cursor_t *cursor;
}sprite_t;

typedef struct sound_s {

}sound_t;

typedef struct music_s {

}music_t;

//utilisez cette struct pour y mettre toutes les listes chainées de data
//ou block de donnée à créer dans une struct approprié

typedef struct stock_data_s {
    int data;
}stock_data_t;

typedef struct game {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent *event;
    sprite_t *sprite;
    sound_t *sound;
    music_t *music;
    text_t *text[10];
    clock_data_t *clock;
    stock_data_t *data;
}game_t;