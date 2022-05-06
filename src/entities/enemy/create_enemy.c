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
    enemy->base_speed = NOT_SET;
    enemy->clock_data = NULL;
    enemy->pos = (sfVector2f){NOT_SET, NOT_SET};
    enemy->animator_standing = NULL;
    enemy->animator_moving = NULL;
    return (enemy);
}

enemy_t *init_basic_enemy(sfVector2f pos)
{
    enemy_t *enemy = create_enemy();

    if (enemy == NULL)
        return (NULL);
    enemy->name = my_strdup("basic_temp_name");
    enemy->clock_data = init_clock_data(0.03);
    enemy->moving_state = IDDLE;
    enemy->stat = (stat_t){.actual_life=10, .armor=0, .health=10, .level=1,
    .power=1, .speed=1, .xp=10, .top_bar=NULL};
    enemy->base_speed = 3.f;
    enemy->type_enemy = MOB;
    enemy->pos = pos;
    enemy->animator_standing = load_animator("scripts/animator/iddle.ani");
    enemy->animator_moving = load_animator("scripts/animator/iddle.ani");
    enemy->animator_moving->clock_data->framerate_seconds *= 2;
    return (enemy);
}

enemy_t *create_enemy_depend_of_category(int category_enemy, sfVector2f pos)
{
    int enum_categories[] = {BASIC_ENEMY, 0};
    enemy_t *(*functions_enemy_creation[])(sfVector2f) = {init_basic_enemy, NULL};

    for (int i = 0; enum_categories[i] != 0; i++) {
        if (category_enemy == enum_categories[i]) {
            return (functions_enemy_creation[i](pos));
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

int add_enemy(int category_enemy, enemies_list_t **enemies_list, sfVector2f pos)
{
    if (enemies_list == NULL || category_enemy <= 0)
        return (84);
    enemy_t *enemy = create_enemy_depend_of_category(category_enemy, pos);
    if (enemy == NULL)
        return (84);
    put_in_enemy(enemies_list, enemy);
    return (0);
}
