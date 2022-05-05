/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_stats
*/

#include "struct_var.h"
#include "my.h"

int init_stats(stat_t **stat)
{
    (*stat) = my_calloc(1, sizeof(stat_t));
    if ((*stat) == NULL)
        return (84);
    (*stat)->actual_life = 100;
    (*stat)->armor = 0;
    (*stat)->health = 100;
    (*stat)->power = 10;
    (*stat)->speed = 1;
    (*stat)->level = 1;
    (*stat)->xp = 0;
    (*stat)->top_bar = load_sprite_data("assets/background/top_bar.png");
    sfSprite_setPosition((*stat)->top_bar->sprite, (sfVector2f){0, 0});
    sfSprite_setScale((*stat)->top_bar->sprite, (sfVector2f){2, 2});
    return (0);
}