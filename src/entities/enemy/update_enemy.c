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

    if (enemy == NULL)
        return;
    scaling = sqrt(pow(pos.x - enemy->pos.x, 2) + pow(pos.y - enemy->pos.y, 2))
    / (enemy->base_speed * enemy->stat.speed);
    if (scaling <= 1) {
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
    if (enemy->moving_state == IDDLE)
        update_animator(enemy->animator_standing);
    else if (enemy->moving_state == MOVING)
        update_animator(enemy->animator_moving);
    drain_clock_data(enemy->clock_data);
    while (update_clock_data(enemy->clock_data)) {
        move_enemy_to_pos(enemy, game->player->pos);
    }
    sfSprite_setPosition(enemy->animator_standing->sprite_data->sprite,
    enemy->pos);
}
