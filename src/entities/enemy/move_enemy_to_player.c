/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** move_enemy_to_player
*/

#include "struct_var.h"

void change_enemy_direction(sfVector2f *enemy_core, sfVector2f *pos,
enemy_t *enemy)
{
    if (enemy_core->x - pos->x > 0) {
        enemy->actual_animator->sprite_data->rect.top = 0;
    } else {
        enemy->actual_animator->sprite_data->rect.top =
        enemy->actual_animator->size_image.y;
    }
    sfSprite_setTextureRect(enemy->actual_animator->sprite_data->sprite,
    enemy->actual_animator->sprite_data->rect);
}

static void move_enemy_to_pos_animator(sfVector2f *enemy_core, sfVector2f *pos,
float distance, enemy_t *enemy)
{
    float scaling = 0;

    if (distance >= enemy->agro_distance) {
        re_set_animator(&(enemy->actual_animator),
        &(enemy->animator_standing));
        return;
    } else
        re_set_animator(&(enemy->actual_animator), &(enemy->animator_moving));
    change_enemy_direction(enemy_core, pos, enemy);
    scaling = distance / (enemy->base_speed * enemy->stat.speed);
    if (scaling <= 1) {
        enemy->pos.x = pos->x - (enemy->actual_animator->size_image.x *
        enemy->actual_animator->sprite_data->scale.x / 2);
        enemy->pos.y = pos->y - (enemy->actual_animator->size_image.y *
        enemy->actual_animator->sprite_data->scale.y / 2);
        return;
    }
    enemy->pos.x += (pos->x - enemy_core->x) / scaling;
    enemy->pos.y += (pos->y - enemy_core->y) / scaling;
}

void move_enemy_to_pos(enemy_t *enemy, sfVector2f pos)
{
    float distance = 0;
    sfVector2f enemy_core;

    if (enemy == NULL)
        return;
    pos.x += 150;
    pos.y += 200;
    enemy_core.x = enemy->pos.x + (enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x / 2);
    enemy_core.y = enemy->pos.y + (enemy->actual_animator->size_image.y *
    enemy->actual_animator->sprite_data->scale.y / 2);
    distance = get_distance(enemy_core, pos);
    move_enemy_to_pos_animator(&enemy_core, &pos, distance, enemy);
}