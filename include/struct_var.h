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
#include <stdlib.h>

/************************** global ***********************************/

#define NOT_SET 0
#define sfKeyReturn sfKeyInsert
#define sfKeyEnter sfKeyInsert
#define PI 3.14159265358979323846

/************************** enum ***********************************/

enum types_weapon {SWORD = 1, SPEAR, GLOVES, GUN};
enum types_armor {HELMET = 1, CHESTPLATE, LEGGINGS, BOOTS};
enum types_bonus_basic {HEALTH = 1, REGENERATION,
POWER, ARMOR, SPEED, CHARISMA};
enum types_enemy {MOB = 1, MINI_BOSS, BOSS};
enum deph_background {FRONTGROUND = 1, MIDGROUND, BACKGROUND};
enum scene_background_t {MENU = 1, SETTINGS, CINEMATIC, ROOM, CITY,
FOREST, LABO};
enum moving_states {IDDLE = 1, MOVING, RUNNING};

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
typedef struct clock_simple_s clock_simple_t;
typedef struct background_s background_t;
typedef struct forest_s forest_t;
typedef struct town_s town_t;
typedef struct laboratory_s laboratory_t;
typedef struct bedroom_s bedroom_t;
typedef struct settings_s settings_t;
typedef struct text_zone_s text_zone_t;
typedef struct game_s game_t;
typedef struct cinematic_s cinematic_t;
typedef struct menu_s menu_t;
typedef struct loot_s loot_t;
typedef struct framebuffer_s framebuffer_t;
typedef struct nest_particle_s nest_particle_t;
typedef struct particle_s particle_t;
typedef struct inventory_s inventory_t;
typedef struct enemies_list_s enemies_list_t;
typedef struct sound_music_s sound_music_t;
typedef struct pause_menu_s pause_menu_t;

/************************** struct ***********************************/

struct sound_music_s {
    sfMusic *music;
    sfSoundBuffer *sound_buff_damage;
    sfSound *damage;
    sfSoundBuffer *sound_buff_terry;
    sfSound *terry;
    sfSoundBuffer *sound_buff_teleport;
    sfSound *teleport;
};

struct cinematic_s {
    sprite_data_t *skip_button;
    sprite_data_t *light;
    sprite_data_t *city;
    animator_t *anim_player_walk;
    animator_t *anim_enemy_run;
    clock_data_t *clock_move_player;
    clock_data_t *clock_move_enemy;
    text_zone_t *text_zone;
    bool walk;
    bool run;
};

struct dialogues_s {
    text_zone_t *text_zone;
    bool binary_reponse;
    dialogues_t **next;
};

struct inventory_s {
    bool display_inventory;
    sprite_data_t *sprite_data;
    armor_t *helmet;
    armor_t *chestplate;
    armor_t *pant;
    armor_t *boots;
    weapon_t *weapon;
};

struct loot_s {
    sfVector2f position;
    int armor_or_weapon;
    armor_t *armor;
    weapon_t *weapon;
    int id;
    clock_data_t *disparition_clock;
};

struct npc_s {
    sprite_data_t *sprite_data;
    bool display;
    text_zone_t *dialogue;
    int distance_to_travel;
    bool display_text;
    enum scene_background_t scene;
};

struct stat_s {
    int actual_life;
    int health;
    int armor;
    int power;
    int speed;
    int level;
    int xp;
    sprite_data_t *top_bar;
};

struct enemies_list_s {
    enemy_t *enemy;
    enemies_list_t *next;
    enemies_list_t *prev;
};

struct enemy_s {
    enum types_enemy type_enemy;
    int distance_to_travel;
    enum scene_background_t scene;
    char *name;
    int id;
    stat_t stat;
    float base_speed;
    bool display;
    sfVector2f pos;
    clock_data_t *clock_data;
    float agro_distance;
    enum moving_states moving_state;
    animator_t *actual_animator;
    animator_t *animator_standing;
    animator_t *animator_moving;
    nest_particle_t *nest_particle;
    clock_data_t *attack_clock;
    framebuffer_t *healthbar;
};

struct framebuffer_s {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
};

struct particle_s {
    float acceleration;
    float speed;
    sfVector2f position;
    particle_t *next;
    sfColor color;
    particle_t *prev;
};

struct nest_particle_s {
    framebuffer_t *framebuffer;
    sfVector2f offset;
    particle_t *all_particles;
    sfColor color;
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
    clock_data_t *anim;
    clock_data_t *player;
    clock_data_t *c_punch;
    clock_data_t *c_gun;
    clock_data_t *c_sword;
    clock_data_t *c_spear;
    clock_data_t *clock_update_animator;
    clock_data_t *attack_clock;
    animator_t *run;
    animator_t *walk;
    animator_t *iddle;
    animator_t *sword;
    animator_t *gun;
    animator_t *spear;
    animator_t *punch;
    sfVector2f pos;
    bool player_walk;
    bool player_run;
    bool move_up;
    bool move_down;
    bool move_left;
    bool move_right;
    bool attack;
    bool direction;
    int weapon;
    int player_mode;
    int traveled_distance;
    stat_t *stat;
    inventory_t *inventory;
    sfIntRect hitbox;
    sfColor hitbox_color;
};

struct clock_data_s {
    sfClock *clock;
    float elapsed_time;
    float framerate_seconds;
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

struct pause_menu_s {
    sprite_data_t *sprite;
    sprite_data_t *back;
    sfVector2f *rectangles_positions;
    sfVector2f *rectangles_sizes;
    bool display_pause;
    bool display_pause_sprite;
};

struct menu_s {
    sprite_data_t *sprite;
    sfRectangleShape **settings_rectangles;
    sfVector2f *rectangles_positions;
    sfVector2f *rectangles_sizes;
    int fps;
    bool sound;
    bool music;
    bool how_to_play_mode;
    text_zone_t *how_to_play;
    pause_menu_t *pause;
};

struct background_s {
    menu_t *menu;
    forest_t *forest[2];
    town_t *town[2];
    laboratory_t *laboratory;
    bedroom_t *bedroom;
    enum scene_background_t scene_background;
    loot_t *loot[10];
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

struct game_s {
    int click[2];
    sfRenderWindow *window;
    sfEvent event;
    enemy_t *enemy;
    background_t *background;
    int distance[2];
    player_t *player;
    npc_t *npc[5];
    sfClock *clock;
    clock_data_t *clock_secondary;
    cinematic_t *cinematic;
    enemies_list_t *enemies_list;
    sound_music_t *sound_music;
};

/************************** functions ***********************************/

//* elementary

char *get_file(char *path);
char **get_data_from_file(char *path);
void freen(void *ptr);
int put_str_error(char *str);
int get_number_of_files_in_directory(char *directory,
char *expected_extension);
char **get_files_from_directory(char *directory, char *expected_extension);
void freen_array(void *array);
bool verif_extension(char *filename, char *expected_extension);
float get_distance(sfVector2f a, sfVector2f b);

//*enemy

enemy_t *create_enemy(void);
void destroy_enemy(enemy_t **enemy);
enemy_t *load_enemy(char *path);
enemy_t *fill_enemy(enemy_t *enemy, char **data);
enemy_t *spawn_mob_enemy(sfVector2f pos, sfVector2i spawn_inf);
enemy_t *spawn_mini_boss_enemy(sfVector2f pos, sfVector2i spawn_inf);
enemy_t *spawn_boss_enemy(sfVector2f pos, sfVector2i spawn_inf);
void display_enemy(enemy_t *enemy, sfRenderWindow *window);
void update_enemy(enemy_t *enemy, game_t *game);
bool is_dead_enemy(enemy_t *enemy);
int add_enemy(int category_enemy, enemies_list_t **enemies_list,
sfVector2f pos, sfVector2i spawn_inf);
void update_enemies_list(enemies_list_t **enemies_list, game_t *game);
void display_enemies_list(enemies_list_t **enemies_list,
sfRenderWindow *window);
void update_dead_list(enemies_list_t **enemies_list, player_t *player,
loot_t **loot);
bool init_enemy(game_t *game);
void attack_player(enemy_t *enemy, player_t *player);
void attack_enemy(enemy_t *enemy, game_t *game);
void move_enemy_left(game_t *game, int speed);
void move_enemy_right(game_t *game, int speed);
void update_healthbar(enemy_t *enemy);
void display_healthbar(enemy_t *enemy, sfRenderWindow *window);
void kill_all_enemy(enemies_list_t **enemies_list, player_t *player,
loot_t **loot);

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
void update_animator(animator_t *animator, game_t *game);
void re_set_animator(animator_t **target, animator_t **giver);

//* clock_data

void set_framerate_clock_data(clock_data_t *clock, float framerate);
clock_data_t *create_clock_data(void);
void drain_clock_data(clock_data_t *clock);
bool update_clock_data(clock_data_t *clock);
void destroy_clock_data(clock_data_t **clock_data);
clock_data_t *init_clock_data(float framerate_seconds);
void reset_clock_data(clock_data_t *clock);

//* event management

int event_handler(game_t *game);
int manage_key(game_t *game);
int manage_key_d(game_t *game);
int manage_key_z(game_t *game);
int manage_key_s(game_t *game);
int manage_key_q(game_t *game);
int manage_key_f(game_t *game);
int manage_attack_key(game_t *game);
bool room_to_city(game_t *game);
bool city_to_room(game_t *game);
bool city_to_forest(game_t *game);
bool forest_to_city(game_t *game);
bool forest_to_labo(game_t *game);
bool labo_to_forest(game_t *game);
void move_player_run(player_t *player, game_t *game);
void move_player_walk(player_t *player, game_t *game);
void detect_press_q_and_d(player_t *player, game_t *game);
void display_text(game_t *game);

//* game management

bool initialize_game(game_t **game);
void display(game_t *game);
void update(game_t *game);
void manage_up(game_t *game);
void manage_down(game_t *game);
bool init_game(game_t *game);

//* cinematic

void create_sprites_cinematic(cinematic_t *cinematic);
void analyse_events(cinematic_t *cinematic);
void display_sprite_cinematic(game_t *game);
void call_clock_cine(cinematic_t *cinematic);
void clock_cine_text(cinematic_t **cinematic);
void create_sprite_skip_button(cinematic_t *cinematic);
void create_sprite_cine_player(cinematic_t *cinematic);
void create_sprite_cine_enemy(cinematic_t *cinematic);
void create_sprite_cine_city(cinematic_t *cinematic);
void create_sprite_cine_light(cinematic_t *cinematic);
bool init_cinematic(cinematic_t **cinematic);
void skip_cinematic(game_t *game);
void clock_cine_text(cinematic_t **cinematic);

//* text zone

int create_text_zone(text_zone_t **text_zone, char *text_string);
bool display_one_more_char(text_zone_t **text_zone);
void display_text_zone(sfRenderWindow *window, text_zone_t *text_zone);

//* menu

bool initialize_menu(menu_t **menu);
int go_to_good_menu(sfVector2i position, game_t *game);
sfVector2f *initialize_positions(char *positions_buffer, int nb_of_zones);
void handle_menu_events(game_t *game);
void handle_settings_events(game_t *game);
int initialize_settings_rectangles(menu_t *menu, game_t *game);
void set_fps_30(game_t *game);
void set_fps_60(game_t *game);
void set_fps_120(game_t *game);
void sound_on(game_t *game);
void sound_off(game_t *game);
void music_on(game_t *game);
void music_off(game_t *game);
int how_to_play(game_t *game);
int initialize_how_to_play(game_t *game);
bool display_one_more_char(text_zone_t **text_zone);
void update_how_to_play(menu_t *menu);

//* background

bool init_back(background_t *background);
bool init_forest(forest_t *forest[2]);
bool init_town(town_t *town[2]);
sprite_data_t *set_sprite(sprite_data_t *sprite);
void move_loot(loot_t **loot, int to_move);
void move_background_left(game_t *game, int speed);
void move_background_right(game_t *game, int speed);

//* player

void display_player_sprites(player_t *player, game_t *game);
bool init_player(player_t *player);
bool init_player_clock(player_t *player);
int init_stats(stat_t **stat);
void display_stats(game_t *game);
int detect_if_key_pressed(player_t *player);
void display_hitbox(sfIntRect rect, sfRenderWindow *window, sfColor color);
void upgrade_level(stat_t *stat);
void handle_stats(stat_t *stat);
void win_xp(stat_t *stat, int how_much_xp);
void player_animation_sword(player_t *player);
void player_animation_gun(player_t *player);
void player_animation_punch(player_t *player);
void player_animation_spear(player_t *player);
void player_animation_run(player_t *player);
void player_animation_walk(player_t *player);
void player_animation_iddle(player_t *player);
bool init_player_animator_move(player_t *player);

//* particle

void destroy_framebuffer(framebuffer_t **framebuffer);
framebuffer_t *create_framebuffer(unsigned int width, unsigned int height);
nest_particle_t *create_nest_particle(int number_of_particle,
sfVector2i size_framebuffer);
void update_nest_particle(nest_particle_t *nest_particle, float delta_time);
void put_nest_particle_on_framebuffer(nest_particle_t *nest_particle);
void destroy_nest_particle(nest_particle_t **nest_particle);

//* inventory

void spawn_random_loot(loot_t **loot, sfVector2f pos);
void display_loot(game_t *game);
void get_loot(game_t *game);
bool init_loot(loot_t *loot[10]);
void display_inventory(game_t *game);
bool init_inventory(inventory_t **inventory);
void invert_display_of_inventory(inventory_t *inventory);
void add_loot_to_inventory(inventory_t *inventory, loot_t *loot);
void add_helmet(inventory_t *inventory, loot_t *loot);
void add_chestplate(inventory_t *inventory, loot_t *loot);
void add_pant(inventory_t *inventory, loot_t *loot);
void add_boots(inventory_t *inventory, loot_t *loot);
void add_weapon(inventory_t *inventory, loot_t *loot);
void remove_loot(loot_t *loot[10]);

//* npc

void display_npc(game_t *game);
bool init_npc(npc_t *npc[5]);
void update_npc(game_t *game);
void move_npc_left(game_t *game, int speed);
void move_npc_right(game_t *game, int speed);

//* sound / music

bool init_sound(sound_music_t **sound_music);

//* enemy

void attack_player(enemy_t *enemy, player_t *player);

//* pause

void display_pause(game_t *game);
void manage_pause(game_t *game);
