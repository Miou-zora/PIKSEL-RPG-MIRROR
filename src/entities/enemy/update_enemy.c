/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_enemy
*/

#include "struct_var.h"
#include "math.h"
#include "my.h"

void set_animator(enemy_t *enemy)
{
    enemy->animator_standing = load_animator("scripts/animator/iddle.ani");
    enemy->animator_moving = load_animator("scripts/animator/iddle.ani");
    enemy->actual_animator = enemy->animator_standing;
    enemy->animator_moving->clock_data->framerate_seconds = 0.1;
}

void update_enemy_drain(enemy_t *enemy, game_t *game)
{
    update_animator(enemy->actual_animator, game);
    drain_clock_data(enemy->clock_data);
    while (update_clock_data(enemy->clock_data)) {
        if (game->background->menu->pause->display_pause == false) {
            move_enemy_to_pos(enemy, game->player->pos);
            update_nest_particle(enemy->nest_particle, 1);
        }
    }
}

void update_enemy(enemy_t *enemy, game_t *game)
{
    if (enemy == NULL)
        return;
    update_enemy_drain(enemy, game);
    if (enemy->scene == game->background->scene_background
    && ((enemy->distance_to_travel - 60 < game->player->traveled_distance
    && enemy->distance_to_travel + 60 > game->player->traveled_distance)
    || (enemy->pos.x < 2000 && enemy->pos.x > -150))
    ) {
        enemy->display = true;
    } else
        enemy->display = false;
    update_healthbar(enemy);
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
        if (game->background->menu->pause->display_pause == false) {
            attack_player((*cursor)->enemy, game->player, game);
        }
        if (game->player->attack == true) {
            attack_enemy((*cursor)->enemy, game);
        }
        cursor = &((*cursor)->next);
    }
    update_dead_list(enemies_list, game->player,
    (loot_t **)&(game->background->loot));
}
