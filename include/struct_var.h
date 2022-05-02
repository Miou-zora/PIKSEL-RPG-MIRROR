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
#define sfKeyReturn sfKeyInsert

/************************** enum ***********************************/

enum types_weapon {SWORD = 1, SPEAR, GLOVES, GUN};
enum types_armor {HELMET = 1, CHESTPLATE, LEGGINGS, BOOTS};
enum types_bonus_basic {HEALTH = 1, REGENERATION,
POWER, ARMOR, SPEED, CHARISMA};
enum types_enemy {MOB = 1, MINI_BOSS, BOSS};
enum deph_background {FRONTGROUND = 0, MIDGROUND, BACKGROUND};
enum scene_background_t {ROOM = 0, CITY, CITY_FOREST, FOREST,
FOREST_LABO, LABO};

/************************** typedef ***********************************/

typedef struct armor_s armor_t;
typedef struct weapon_s weapon_t;
typedef struct sprite_data_s sprite_data_t;
typedef struct animator_s animator_t;
typedef struct clock_data_s clock_data_t;
typedef struct enemy_s enemy_t;
typedef struct npc_s npc_t;
typedef struct dialogues_s dialogues_t;
typedef struct enemy_sprite_s enemy_sprite_t;
typedef struct stat_s stat_t;
typedef struct scene_s scene_t;
typedef struct selection_zone_s selection_zone_t;
typedef struct settings_infos_s settings_infos_t;
typedef struct player_s player_t;
typedef struct clock_player_s clock_player_t;
typedef struct background_s background_t;
typedef struct forest_s forest_t;
typedef struct town_s town_t;
typedef struct laboratory_s laboratory_t;
typedef struct bedroom_s bedroom_t;
typedef struct settings_s settings_t;
typedef struct text_zone_s text_zone_t;

/************************** struct ***********************************/

struct dialogues_s {
    text_zone_t *text_zone;
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
    int actual_life;
    int health;
    int armor;
    int power;
    int speed;
};

struct enemy_s {
    enum types_enemy type_enemy;
    char *name;
    int id;
    stat_t *stat;
    sprite_data_t *sprite_data;
    animator_t *animator_standing;
    animator_t *animator_moving;
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

struct weapon_s {
    char *name;
    int id;
    enum types_weapon type_weapon;
    int rarity;
    int damage;
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
    clock_player_t *anim;
    clock_player_t *player;
    clock_player_t *c_sword;
    clock_player_t *c_punch;
    clock_player_t *c_gun;
    clock_player_t *c_spear;
    animator_t *run;
    animator_t *walk;
    animator_t *iddle;
    animator_t *sword;
    animator_t *gun;
    animator_t *spear;
    animator_t *punch;
    sfVector2f pos;
    int player_mode;
    bool player_walk;
    bool player_run;
    bool move_up;
    bool move_down;
    bool move_left;
    bool move_right;
    bool attack;
    bool direction;
    int weapon;
};

struct clock_player_s {
    sfClock *clock;
    sfTime time;
    float seconds;
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

struct town_s {
    sprite_data_t *sprite;
};

struct bedroom_s {
    sprite_data_t *sprite;
};

struct laboratory_s {
    sprite_data_t *sprite;
};

struct background_s {
    forest_t *forest[2];
    town_t *town[2];
    laboratory_t *laboratory;
    bedroom_t *bedroom;
};

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
    sprite_data_t *text_zone_sprite;
    clock_data_t *text_clock;
    bool enter_is_pressed;
};

typedef struct game {
    int click[2];
    sfRenderWindow *window;
    enemy_t *enemy;
    background_t *background;
    enum scene_background_t scene_background;
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

//*enemy

enemy_t *create_enemy(void);
void destroy_enemy(enemy_t **enemy);
enemy_t *load_enemy(char *path);
enemy_t *fill_enemy(enemy_t *enemy, char **data);

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
void print_all_armors(armor_t **armors);

//* weapon

void destroy_weapon(weapon_t **weapon);
weapon_t *create_weapon(void);
weapon_t *load_weapon(char *filepath);
weapon_t *fill_weapon(weapon_t *weapon, char **data);
weapon_t **create_all_weapons(char **all_files);
weapon_t **fill_all_weapons(weapon_t **weapons, char **all_files);
weapon_t **load_all_weapons(char *path);
void destroy_all_weapons(weapon_t ***weapon);
void print_all_weapons(weapon_t **weapons);
void print_weapon(weapon_t *weapon);

//* sprite_data

void destroy_sprite_data(sprite_data_t **sprite_data);
sprite_data_t *load_sprite_data(char *filename);
sprite_data_t *create_sprite_data(void);

//* animator

animator_t *create_animator(void);
void refresh_animator(animator_t *animator);
void destroy_animator(animator_t **animator);
animator_t *load_animator(char *path);
void increment_animator_image_pos(animator_t *animator);
animator_t *fill_animator(animator_t *animator, char **data);
void update_animator(animator_t *animator);

//* clock_data

void set_framerate_clock_data(clock_data_t *clock, int framerate);
clock_data_t *create_clock_data(void);
void drain_clock_data(clock_data_t *clock);
bool update_clock_data(clock_data_t *clock);
void destroy_clock_data(clock_data_t **clock_data);

//***********************init fonctions player********************************/

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
// void update_clock(clock_data_t *clock);
// void free_all(game_t *game);
// int my_rpg(void);
// void set_mouse_cursor(game_t *game);

//**************************init fonctions***********************************/

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
int initialize_structures(scene_t **menu,
clock_data_t **principal_clock, settings_t **settings);

//************************set event fonctions*********************************/

int change_menu(sfEvent *event, scene_t *scene, settings_t **settings_struct);
void handle_settings(scene_t **scene, sfEvent *event, settings_t *settings);
void handle_fps(settings_t *settings, sfEvent *event);
void handle_sound(settings_t *settings, sfEvent *event);
void handle_music(settings_t *settings, sfEvent *event);
void handle_quit(scene_t *scene);
int go_to_good_menu(scene_t *scene, settings_t *settings_struct);
void analyse_event(sfEvent event, game_t *game);

//**************************free functions************************************/

int free_scene(scene_t *scene);
void free_game(scene_t *scene, settings_t *settings,
clock_data_t *clock, dialogues_t *dialogue);
void free_settings(settings_infos_t *settings);

//************************text zone functions*********************************/

int create_text_zone(text_zone_t **text_zone, char *text_string);
void display_text_zone(sfRenderWindow *window, text_zone_t *text_zone);
void display_one_more_char(text_zone_t **text_zone);
void free_text_zone(text_zone_t *text_zone);

//*************************dialogue functions*********************************/

int create_dialogue_list(dialogues_t **dialogue, char *path_to_file,
int question_or_monologue);
int create_dialogue_bubble(dialogues_t **bubble, char *string);
int free_dialogue(dialogues_t **dialogue);