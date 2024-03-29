/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** move_enemy
*/

#include "struct_var.h"
#include "my.h"

static void move_enemy_to_left(game_t *game, int speed)
{
    if (game->enemies_list == NULL)
        return;
    while (game->enemies_list->next != NULL) {
        if (game->enemies_list->enemy->display == true)
            game->enemies_list->enemy->pos.x += 20 * speed;
        game->enemies_list = game->enemies_list->next;
    }
}

void move_enemy_left(game_t *game, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyQ))
        return;
    else {
        move_enemy_to_left(game, speed);
    }
}

static void move_enemy_to_right(game_t *game, int speed)
{
    if (game->enemies_list == NULL)
        return;
    while (game->enemies_list->next != NULL) {
        if (game->enemies_list->enemy->display == true)
            game->enemies_list->enemy->pos.x -= 20 * speed;
        game->enemies_list = game->enemies_list->next;
    }
}

void move_enemy_right(game_t *game, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyQ))
        return;
    else {
        move_enemy_to_right(game, speed);
    }
}
