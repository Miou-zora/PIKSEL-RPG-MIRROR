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
    enemy->stat = NOT_SET;
    enemy->animator_standing = NULL;
    enemy->animator_moving = NULL;
    return (enemy);
}
