/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg
*/

#pragma once

typedef struct sprite_data_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f position;
} sprite_data_t;

typedef struct point_s {
    int x;
    int y;
} point_t;

typedef struct animator_s {
    int number_image;
    point_t *nb_image_xy;
    sprite_data_t *sprite_data;
    point_t *image;
} animator_t;

typedef struct weapon_s {
    sfSprite *sprite;
    sfTexture *texture;
    // enum type_weapon;
    int nb_of_the_bonus;
    animator_t *animator;
} weapon_t;

typedef struct armor_s {
    sfSprite *sprite;
    sfTexture *texture;
    // enum type_bonus;
    int nb_of_the_bonus;
    animator_t *animator;
} armor_t;

typedef struct inventory_s {
    int actual_helmet;
    int actual_chestplate;
    int actual_leggings;
    int actual_boots;
    weapon_t *actual_weapon;
    int *stuff;
} inventory_t;

typedef struct level_s {
    int level;
    int max_level;
    int xp;
    int xp_to_pass_level;
} level_t;

typedef struct characteristics_s {
    int life;
    int regeneration;
    int power;
    armor_t *armor;
    int speed;
    int charisma;
} characteristics_t;

typedef struct main_character_s {
    int actual_life;
    level_t *level;
    characteristics_t *characteristics;
    // enum actual_animation;
    inventory_t *inventory;
} main_character_t;

typedef struct vector_s {
    void *object;
    void *next;
    void *prev;
} vector_t;

typedef struct my_clock_s {
    sfClock *clocksfInt64;
    sfInt64 elapsed_time;
    sfTime currElapsedTime;
} my_clock_t;

typedef struct scene_s {
    sfRenderWindow *window;
    sprite_data_t *background;
    sfRectangleShape *hitbox;
} scene_t;