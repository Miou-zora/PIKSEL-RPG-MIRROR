/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** spawn_enemy
*/

#include "struct_var.h"
#include "my.h"

void set_animator(enemy_t *enemy)
{
    enemy->animator_standing = load_animator("scripts/animator/iddle.ani");
    enemy->animator_moving = load_animator("scripts/animator/iddle.ani");
    enemy->actual_animator = enemy->animator_standing;
    enemy->animator_moving->clock_data->framerate_seconds = 0.1;
}

enemy_t *spawn_mob_enemy(sfVector2f pos, sfVector2i spawn_info)
{
    enemy_t *enemy = create_enemy();

    if (enemy == NULL)
        return (NULL);
    enemy->name = my_strdup("basic_temp_name");
    enemy->clock_data = init_clock_data(0.03);
    enemy->moving_state = IDDLE;
    enemy->stat = (stat_t){.actual_life = 100, .armor = 0, .health = 10,
    .level = 1, .power = 1, .speed = 1, .xp = 50, .top_bar = NULL};
    enemy->base_speed = 3.f;
    enemy->type_enemy = MOB;
    enemy->pos = pos;
    enemy->scene = spawn_info.x;
    enemy->distance_to_travel = spawn_info.y;
    set_animator(enemy);
    enemy->agro_distance = 1000.f;
    enemy->nest_particle = NULL;
    enemy->healthbar = create_framebuffer(enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x, 20);
    return (enemy);
}

enemy_t *spawn_mini_boss_animator(enemy_t *enemy)
{
    enemy->animator_standing = load_animator("scripts/animator/iddle.ani");
    enemy->animator_moving = load_animator("scripts/animator/iddle.ani");
    enemy->actual_animator = enemy->animator_standing;
    enemy->animator_moving->clock_data->framerate_seconds = 0.08;
    enemy->agro_distance = 1000.f;
    enemy->nest_particle = create_nest_particle(500, (sfVector2i){200, 200});
    enemy->nest_particle->color = (sfColor){255, 255, 255, 255};
    enemy->healthbar = create_framebuffer(enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x, 20);
    return (enemy);
}

enemy_t *spawn_mini_boss_enemy(sfVector2f pos, sfVector2i spawn_info)
{
    enemy_t *enemy = create_enemy();

    if (enemy == NULL)
        return (NULL);
    enemy->name = my_strdup("basic_temp_name");
    enemy->clock_data = init_clock_data(0.03);
    enemy->moving_state = IDDLE;
    enemy->stat = (stat_t){.actual_life = 1000, .armor = 0, .health = 1000,
    .level = 1, .power = 1, .speed = 1, .xp = 150, .top_bar = NULL};
    enemy->base_speed = 3.6f;
    enemy->type_enemy = MINI_BOSS;
    enemy->pos = pos;
    enemy->scene = spawn_info.x;
    enemy->distance_to_travel = spawn_info.y;
    enemy = spawn_mini_boss_animator(enemy);
    return (enemy);
}

enemy_t *spawn_boss_enemy_animator(enemy_t *enemy)
{
    enemy->animator_standing = \
    load_animator("scripts/animator/iddle_boss.ani");
    enemy->animator_standing->sprite_data->scale = (sfVector2f){8, 8};
    sfSprite_setScale(enemy->animator_standing->sprite_data->sprite,
    (sfVector2f){8, 8});
    enemy->animator_moving = load_animator("scripts/animator/moving_boss.ani");
    enemy->animator_moving->sprite_data->scale = (sfVector2f){8, 8};
    sfSprite_setScale(enemy->animator_moving->sprite_data->sprite,
    (sfVector2f){8, 8});
    enemy->agro_distance = 2000.f;
    enemy->nest_particle = create_nest_particle(50000,
    (sfVector2i){250, 250});
    enemy->animator_moving->clock_data->framerate_seconds = 0.05;
    enemy->actual_animator = enemy->animator_standing;
    enemy->nest_particle->color = (sfColor){255, 0, 255, 255};
    enemy->healthbar = create_framebuffer(enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x, 20);
    return (enemy);
}

enemy_t *spawn_boss_enemy(sfVector2f pos, sfVector2i spawn_info)
{
    enemy_t *enemy = create_enemy();

    if (enemy == NULL)
        return (NULL);
    enemy->name = my_strdup("basic_temp_name");
    enemy->clock_data = init_clock_data(0.03);
    enemy->moving_state = IDDLE;
    enemy->stat = (stat_t){.actual_life = 10000, .armor = 0, .health = 10000,
    .level = 1, .power = 1, .speed = 1, .xp = 1000, .top_bar = NULL};
    enemy->base_speed = 6.f;
    enemy->type_enemy = BOSS;
    enemy->pos = pos;
    enemy->scene = spawn_info.x;
    enemy->distance_to_travel = spawn_info.y;
    enemy = spawn_boss_enemy_animator(enemy);
    return (enemy);
}
