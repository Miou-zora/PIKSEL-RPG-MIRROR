/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_stats
*/

#include "struct_var.h"
#include "my.h"

display_stat_t *init_display_of_stats(void)
{
    display_stat_t *to_display = my_calloc(1, sizeof(display_stat_t));
    if (to_display == NULL)
        return (NULL);
    to_display->text = my_calloc(5, sizeof(sfText *));
    if (to_display->text == NULL)
        return (NULL);
    to_display->stats = my_calloc(5, sizeof(char *));
    if (to_display->stats == NULL)
        return (NULL);
    for (int i = 0; i < 5; i++) {
        to_display->stats[i] = my_calloc(4, sizeof(char));
        if (to_display->stats[i] == NULL)
            return (NULL);
        to_display->text[i] = sfText_create();
        sfText_setFont(to_display->text[i],
        sfFont_createFromFile("assets/font/font.ttf"));
        if (to_display->text[i] == NULL)
            return (NULL);
    }
    to_display->stats_values = my_calloc(5, sizeof(int *));
    if (to_display->stats_values == NULL)
        return (NULL);
    my_printf("init display\n");
    return (to_display);
}

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
    (*stat)->to_display = init_display_of_stats();
    return (0);
}