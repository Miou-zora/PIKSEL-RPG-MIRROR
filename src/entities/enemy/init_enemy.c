/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_enemy
*/

#include "struct_var.h"
#include "my.h"

void add_enemy_on_city_part_two(game_t *game)
{
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){CITY, 360});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 650},
    // (sfVector2i){CITY, 365});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 800},
    // (sfVector2i){CITY, 370});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){CITY, 450});
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){CITY, 460});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 650},
    // (sfVector2i){CITY, 465});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 800},
    // (sfVector2i){CITY, 470});
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){CITY, 410});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 650},
    // (sfVector2i){CITY, 415});
    add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 800},
    (sfVector2i){CITY, 420});
}

void add_enemy_on_city(game_t *game)
{
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){CITY, 60});
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){CITY, 85});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){CITY, 142});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){CITY, 142});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){CITY, 250});
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){CITY, 260});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 650},
    // (sfVector2i){CITY, 265});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 800},
    // (sfVector2i){CITY, 270});
    add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    (sfVector2i){CITY, 350});
    add_enemy_on_city_part_two(game);
}

void add_enemy_on_forest_part_two(game_t *game)
{
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){FOREST, 350});
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){FOREST, 360});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 650},
    // (sfVector2i){FOREST, 365});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 800},
    // (sfVector2i){FOREST, 370});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){FOREST, 450});
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){FOREST, 460});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 650},
    // (sfVector2i){FOREST, 465});
    add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 800},
    (sfVector2i){FOREST, 470});
}

void add_enemy_on_forest(game_t *game)
{
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){FOREST, 60});
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){FOREST, 85});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){FOREST, 142});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){FOREST, 142});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 600},
    // (sfVector2i){FOREST, 250});
    // add_enemy(MINI_BOSS, &(game->enemies_list), (sfVector2f){2000, 700},
    // (sfVector2i){FOREST, 260});
    // add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 650},
    // (sfVector2i){FOREST, 265});
    add_enemy(MOB, &(game->enemies_list), (sfVector2f){2000, 800},
    (sfVector2i){FOREST, 270});
    add_enemy_on_forest_part_two(game);
}

bool init_enemy(game_t *game)
{
    add_enemy_on_city(game);
    add_enemy_on_forest(game);
    add_enemy(BOSS, &(game->enemies_list), (sfVector2f){1700, 500},
    (sfVector2i){LABO, 0});
    return (false);
}
