/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_enemy
*/

#include "struct_var.h"
#include "math.h"
#include "my.h"

static void move_enemy_to_pos(enemy_t *enemy, sfVector2f pos)
{
    float scaling = 0;
    float distance = 0;

    if (enemy == NULL)
        return;
    distance = sqrt(pow(pos.x - enemy->pos.x, 2) +
    pow(pos.y - enemy->pos.y, 2));
    if (distance >= enemy->agro_distance) {
        if (enemy->actual_animator != enemy->animator_standing) {
            enemy->actual_animator = enemy->animator_standing;
            reset_clock_data(enemy->actual_animator->clock_data);
        }
        return;
    } else {
        if (enemy->actual_animator != enemy->animator_moving) {
            enemy->actual_animator = enemy->animator_moving;
            reset_clock_data(enemy->actual_animator->clock_data);
        }
    }
    scaling = distance / (enemy->base_speed * enemy->stat.speed);
    if (scaling <= 1) {
        enemy->stat.actual_life = 0;
        enemy->pos.x = pos.x;
        enemy->pos.y = pos.y;
        return;
    }
    enemy->pos.x += (pos.x - enemy->pos.x) / scaling;
    enemy->pos.y += (pos.y - enemy->pos.y) / scaling;
}

void update_enemy(enemy_t *enemy, game_t *game)
{
    if (enemy == NULL)
        return;
    update_animator(enemy->actual_animator);
    drain_clock_data(enemy->clock_data);
    while (update_clock_data(enemy->clock_data)) {
        move_enemy_to_pos(enemy, game->player->pos);
        update_nest_particle(enemy->nest_particle, 1);
    }
    sfSprite_setPosition(enemy->animator_standing->sprite_data->sprite,
    enemy->pos);
    sfSprite_setPosition(enemy->animator_moving->sprite_data->sprite,
    enemy->pos);
}

void update_enemies_list(enemies_list_t **enemies_list, game_t *game)
{
    enemies_list_t **cursor = enemies_list;

    while ((*cursor) != NULL) {
        update_enemy((*cursor)->enemy, game);
        cursor = &((*cursor)->next);
    }
    update_dead_list(enemies_list, game->player);
}
