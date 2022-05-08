/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_enemy
*/

#include "struct_var.h"
#include "math.h"
#include "my.h"

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

static void move_enemy_to_pos(enemy_t *enemy, sfVector2f pos)
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

void update_enemy_drain(enemy_t *enemy, game_t *game)
{
    update_animator(enemy->actual_animator, game);
    drain_clock_data(enemy->clock_data);
    drain_clock_data(enemy->attack_clock);
    my_printf("biento\n");
    while (update_clock_data(enemy->clock_data)) {
        my_printf("boucle\n");
        if (game->background->menu->pause->display_pause == false) {
            my_printf("if\n");
            move_enemy_to_pos(enemy, game->player->pos);
            my_printf("if2\n");
            update_nest_particle(enemy->nest_particle, 1);
            my_printf("if3\n");
        }
    }
    while (update_clock_data(enemy->attack_clock)) {
        if (game->background->menu->pause->display_pause == false) {
            attack_player(enemy, game->player);
        }
    }
}

void update_enemy(enemy_t *enemy, game_t *game)
{
    my_printf("h\n");
    if (enemy == NULL)
        return;
    my_printf("r\n");
    update_enemy_drain(enemy, game);
    my_printf("1\n");
    if (enemy->scene == game->background->scene_background
    && enemy->distance_to_travel - 60 < game->player->traveled_distance
    && enemy->distance_to_travel + 60 > game->player->traveled_distance) {
        enemy->display = true;
    } else
        enemy->display = false;
    my_printf("Start\n");
    update_healthbar(enemy);
    my_printf("v\n");
    sfSprite_setPosition(enemy->animator_standing->sprite_data->sprite,
    enemy->pos);
    sfSprite_setPosition(enemy->animator_moving->sprite_data->sprite,
    enemy->pos);
    my_printf("j\n");
}

void update_enemies_list(enemies_list_t **enemies_list, game_t *game)
{
    enemies_list_t **cursor = enemies_list;

    while ((*cursor) != NULL) {
        my_printf("f\n");
        update_enemy((*cursor)->enemy, game);
        my_printf("a\n");
        if (game->player->attack == true) {
            my_printf("b\n");
            attack_enemy((*cursor)->enemy, game);
        }
        my_printf("c\n");
        cursor = &((*cursor)->next);
        my_printf("e\n");
    }
    my_printf("d\n");
    update_dead_list(enemies_list, game->player);
}
