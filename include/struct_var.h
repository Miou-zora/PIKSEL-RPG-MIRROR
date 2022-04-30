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
typedef struct ennemy_sprite_s ennemy_sprite_t; 
typedef struct stat_s stat_t;
typedef struct scene_s scene_t;
typedef struct selection_zone_s selection_zone_t;
typedef struct settings_infos_s settings_infos_t;
typedef struct player_s player_t;
typedef struct background_s background_t;
typedef struct forest_s forest_t;
typedef struct settings_s settings_t;
typedef struct text_zone_s text_zone_t;

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

struct stat_s {
    int health;
    int armor;
    int power;
    int speed;
};

struct ennemy_s {
    enum types_ennemy type_ennemy;
    char *name;
    int id;
    stat_t *stat;
    sprite_data_t *sprite_data;
    int max_left;
    sfClock *clock;
};

struct armor_s {
    char *name;
    int id;
    enum types_armor type_armor;
    enum types_bonus_basic type_bonus_basic;
    int rarity;
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
    clock_data_t *clock_data;
};

struct player_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    animator_t *run;
    animator_t *walk;
    animator_t *iddle;
};

struct clock_data_s {
    sfClock *clocksfInt64;
    sfInt64 elapsed_time;
    sfTime currElapsedTime;
    int framerate;
};

struct selection_zone_s {
    sfRectangleShape *hitbox;
    sfVector2f *positions;
    int current_pos;
    int nb_of_poses;
};

struct settings_infos_s {
    sfRectangleShape **fill_rectangles;
    sfVector2f *rectangles_positions;
    sfVector2f *rectangles_sizes;
};

struct scene_s {
    sfRenderWindow *window;
    sprite_data_t *background;
    selection_zone_t *select_zone;
    settings_infos_t *settings;
    char *zone_name;
};

struct forest_s {
    sprite_data_t *sprite;
};

struct background_s {
    forest_t *forest[2];
    //town_t *town[2];
    //laboratory_t *laboratory[2];
    //bedroom_t *bedroom;
struct settings_s {
    bool sound;
    bool music;
    int fps;
};

struct text_zone_s {
    sfText *text;
    sfFont *font;
    char *text_string;
    char *current_string;
    int which_character;
    sfSprite *sprite_zone;
    sfTexture *texture_zone;
    clock_data_t *text_clock;
    bool enter_is_pressed;
};

typedef struct game {
    int click[2];
    sfRenderWindow *window;
    ennemy_t *ennemy;
    background_t *background;
    int distance[2];
    sfClock *clock;
}game_t;

/************************** functions ***********************************/

//* elementary

char *get_file(char *path);
char **get_data_from_file(char *path);
void freen(void *ptr);
int put_str_error(char *str);
int get_number_of_files_in_directory(char *directory, char *expected_extension);
char **get_files_from_directory(char *directory, char *expected_extension);
void freen_array(void *array);
bool verif_extension(char *filename, char *expected_extension);

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
armor_t **create_all_armors(char **all_files);
armor_t **fill_all_armors(armor_t **armors, char **all_files);
void destroy_all_armors(armor_t ***armors);
armor_t **load_all_armors(char *filepath);
void print_armor(armor_t *armor);

//* sprite_data

void destroy_sprite_data(sprite_data_t **sprite_data);
sprite_data_t *load_sprite_data(char *filename);
sprite_data_t *create_sprite_data(void);

//* animator

animator_t *create_animator(void);
void destroy_animator(animator_t **animator);
animator_t *load_animator(char *path);
animator_t *fill_animator(animator_t *animator, char **data);

//* clock_data

clock_data_t *create_clock_data(void);
void destroy_clock_data(clock_data_t **clock_data);
