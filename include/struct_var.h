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
#include <stdbool.h>

/************************** global ***********************************/

#define NOT_SET 0

/************************** enum ***********************************/

enum types_armor {HELMET = 1, CHESTPLATE, LEGGINGS, BOOTS};
enum types_bonus_basic {HEALTH = 1, REGENERATION,
POWER, ARMOR, SPEED, CHARISMA};
enum types_ennemy {MOB = 1, MINI_BOSS, BOSS};

/************************** typedef ***********************************/

typedef struct armor_s armor_t;
typedef struct sprite_data_s sprite_data_t;
typedef struct animator_s animator_t;
typedef struct clock_data_s clock_data_t;
typedef struct ennemy_s ennemy_t;
typedef struct npc_s npc_t;
typedef struct dialogues_s dialogues_t;

/************************** struct ***********************************/

struct dialogues_s {
    char *text;
    bool text_changed;
    dialogues_t *changed_text;
    bool binary_reponse;
    dialogues_t **next;
    //struct quest *quest_add;
};

struct npc_s {
    char *name;
    sprite_data_t *sprite_data;
    int postion[2];
    struct dialogues *dialogue;
    int index;
};

struct ennemy_s {
    enum types_ennemy type_ennemy;
    char *name;
    int id;
    int health;
    int armor;
    int power;
    int speed;
    sprite_data_t *sprite_data;
};

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
    sfVector2f size_image;
    sprite_data_t *sprite_data;
    clock_data_t *clock;
};

struct clock_data_s {
    sfClock *clocksfInt64;
    sfInt64 elapsed_time;
    sfTime currElapsedTime;
    int time_between_each_actualization;
};

typedef struct game {
    int click[2];
    sfRenderWindow *window;
    sprite_data_t *sprite;
}game_t;

/************************** functions ***********************************/

//* elementary

char *get_file(char *path);
char **get_data_from_file(char *path);
void freen(void **ptr);
int put_str_error(char *str);

//*ennemy

ennemy_t *create_ennemy(void);
void destroy_ennemy(ennemy_t **ennemy);
ennemy_t *fill_ennemy(ennemy_t *ennemy, char **data);
ennemy_t *load_ennemy(char *path);

//* armor

armor_t *create_armor(void);
armor_t *load_armor(char *path);
void destroy_armor(armor_t **armor);
armor_t *fill_armor(armor_t *armor, char **data);

//* sprite_data

void destroy_sprite_data(sprite_data_t **sprite_data);
sprite_data_t *load_sprite_data(const char *filename);
sprite_data_t *create_sprite_data(void);