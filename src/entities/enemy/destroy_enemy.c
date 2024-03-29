/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** destroy_enemy
*/

#include "struct_var.h"
#include "my.h"

void destroy_animators(enemy_t **enemy)
{
    if ((*enemy)->animator_standing != NULL)
        destroy_animator(&((*enemy)->animator_standing));
    if ((*enemy)->animator_moving != NULL)
        destroy_animator(&((*enemy)->animator_moving));
}

void destroy_enemy(enemy_t **enemy)
{
    if (enemy == NULL || *enemy == NULL)
        return;
    if ((*enemy)->name != NULL)
        freen(&((*enemy)->name));
    destroy_animators(enemy);
    if ((*enemy)->clock_data != NULL) {
        destroy_clock_data(&((*enemy)->clock_data));
    }
    freen(enemy);
}

void delete_enemy_from_list(enemies_list_t **enemies_list)
{
    enemies_list_t *over_cursor = (*enemies_list)->next;
    enemies_list_t *cursor = (*enemies_list);

    destroy_nest_particle(&((*enemies_list)->enemy->nest_particle));
    destroy_enemy(&((*enemies_list)->enemy));
    if (cursor->prev != NULL) {
        cursor->prev->next = cursor->next;
    }
    if (cursor->next != NULL) {
        cursor->next->prev = cursor->prev;
    }
    freen(&cursor);
    (*enemies_list) = over_cursor;
}

void update_dead_list(enemies_list_t **enemies_list, player_t *player,
loot_t **loot)
{
    enemies_list_t **cursor = enemies_list;

    while (cursor != NULL && (*cursor) != NULL) {
        if (is_dead_enemy((*cursor)->enemy) == true) {
            player->stat->xp += (*cursor)->enemy->stat.xp;
            spawn_random_loot(loot, (*cursor)->enemy->pos);
            delete_enemy_from_list(cursor);
        }
        if (cursor != NULL && (*cursor) != NULL && (*cursor)->next != NULL) {
            cursor = &((*cursor)->next);
        } else {
            cursor = NULL;
        }
    }
}

void kill_all_enemy(enemies_list_t **enemies_list, player_t *player,
loot_t **loot)
{
    enemies_list_t **cursor = enemies_list;

    while (cursor != NULL && (*cursor) != NULL) {
        if ((*cursor)->enemy != NULL)
            (*cursor)->enemy->stat.actual_life = 0;
        cursor = &((*cursor)->next);
    }
    update_dead_list(enemies_list, player, loot);
}
