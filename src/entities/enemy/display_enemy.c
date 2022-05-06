/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_enemy
*/

#include "struct_var.h"

void display_enemy(enemy_t *enemy, sfRenderWindow *window)
{
    if (enemy == NULL)
        return;
    if (enemy->animator_standing != NULL && enemy->moving_state == IDDLE)
        sfRenderWindow_drawSprite(window,
        enemy->animator_standing->sprite_data->sprite, NULL);
    if (enemy->animator_moving != NULL && enemy->moving_state == MOVING)
        sfRenderWindow_drawSprite(window,
        enemy->animator_moving->sprite_data->sprite, NULL);
}

void display_enemies_list(enemies_list_t **enemies_list, sfRenderWindow *window)
{
    enemies_list_t **cursor = enemies_list;

    while ((*cursor) != NULL) {
        display_enemy((*cursor)->enemy, window);
        cursor = &((*cursor)->next);
    }
}
