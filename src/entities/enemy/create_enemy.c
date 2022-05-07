/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** create_enemy
*/

#include "struct_var.h"
#include "my.h"

enemy_t *create_enemy(void)
{
    enemy_t *enemy = my_calloc(1, sizeof(*enemy));

    if (enemy == NULL)
        return (NULL);
    enemy->type_enemy = NOT_SET;
    enemy->name = NULL;
    enemy->id = NOT_SET;
    enemy->stat = (stat_t){0};
    enemy->moving_state = IDDLE;
    enemy->display = false;
    enemy->base_speed = NOT_SET;
    enemy->distance_to_travel = 0;
    enemy->scene = NOT_SET;
    enemy->clock_data = NULL;
    enemy->pos = (sfVector2f){NOT_SET, NOT_SET};
    enemy->animator_standing = NULL;
    enemy->animator_moving = NULL;
    enemy->agro_distance = 0.f;
    enemy->nest_particle = NULL;
    return (enemy);
}

enemy_t *create_enemy_depend_of_category(int category_enemy, sfVector2f pos,
sfVector2i spawn_info)
{
    int enum_categories[] = {MOB, MINI_BOSS, BOSS, 0};
    enemy_t *(*functions_enemy_creation[])(sfVector2f, sfVector2i) =
    {spawn_mob_enemy, spawn_mini_boss_enemy, spawn_boss_enemy, NULL};

    for (int i = 0; enum_categories[i] != 0; i++) {
        if (category_enemy == enum_categories[i]) {
            return (functions_enemy_creation[i](pos, spawn_info));
        }
    }
    return (NULL);
}

void put_in_enemy(enemies_list_t **enemies_list, enemy_t *enemy)
{
    enemies_list_t **cursor = enemies_list;

    while ((*cursor) != NULL && (*cursor)->next != NULL)
        cursor = &((*cursor)->next);
    if ((*cursor) == NULL) {
        (*cursor) = my_calloc(1, sizeof(*(*cursor)));
        if ((*cursor) == NULL)
            return;
        (*cursor)->prev = NULL;
    } else {
        (*cursor)->next = my_calloc(1, sizeof(*(*cursor)));
        if ((*cursor) == NULL)
            return;
        (*cursor)->next->prev = (*cursor);
        cursor = &((*cursor)->next);
    }
    (*cursor)->next = NULL;
    (*cursor)->enemy = enemy;
}

int add_enemy(int category_enemy, enemies_list_t **enemies_list,
sfVector2f pos, sfVector2i spawn)
{
    if (enemies_list == NULL || category_enemy <= 0)
        return (84);
    enemy_t *enemy = create_enemy_depend_of_category(category_enemy, pos,
    spawn);
    if (enemy == NULL)
        return (84);
    put_in_enemy(enemies_list, enemy);
    return (0);
}
