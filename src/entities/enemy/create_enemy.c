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
    .power=1, .speed=1, .xp=0, .top_bar=NULL};
    enemy->base_speed = 3.f;
    enemy->type_enemy = MOB;
    enemy->pos = pos;
    enemy->animator_standing = load_animator("scripts/animator/iddle.ani");
    enemy->animator_moving = load_animator("scripts/animator/iddle.ani");
    enemy->animator_moving->clock_data->framerate_seconds *= 2;
    return (enemy);
}
