/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_stats
*/

#include "struct_var.h"
#include "my.h"

char *put_in_str(int nb, char *str)
{
    char nb_str[2];

    if (nb >= 0 && nb <= 9) {
        nb_str[0] = nb + 48;
        nb_str[1] = '\0';
        my_strcat(str, nb_str);
        return (str);
    } else if (nb > 9) {
        put_in_str(nb / 10, str);
        put_in_str(nb % 10, str);
    }
    return (str);
}

void fill_stats(char **stats, int *stats_values, game_t *game)
{
    sfText **text = malloc(sizeof(sfText *) * 5);

    for (int i = 0; i < 5; i++) {
        stats[i] = malloc(sizeof(char) * (get_nbrlen(stats_values[i]) + 2));
        stats[i][0] = '\0';
        stats[i] = put_in_str(stats_values[i], stats[i]);
        text[i] = sfText_create();
        sfText_setString(text[i], stats[i]);
        sfText_setFont(text[i],
        sfFont_createFromFile("assets/font/arcadeclassic/ARCADECLASSIC.TTF"));
        sfText_setScale(text[i], (sfVector2f){4, 4});
        sfText_setColor(text[i], sfGreen);
    }
    sfText_setPosition(text[0], (sfVector2f){200, -40});
    sfText_setPosition(text[1], (sfVector2f){550, -40});
    sfText_setPosition(text[2], (sfVector2f){900, -40});
    sfText_setPosition(text[3], (sfVector2f){1400, -40});
    sfText_setPosition(text[4], (sfVector2f){1800, -40});
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawText(game->window, text[i], NULL);
}

void display_stats(game_t *game)
{
    char **stats = malloc(sizeof(char *) * 5);
    int *stats_values = malloc(sizeof(int) * 5);

    stats_values[0] = game->player->stat->level;
    stats_values[1] = game->player->stat->xp;
    stats_values[2] = game->player->stat->actual_life;
    stats_values[3] = game->player->stat->armor;
    stats_values[4] = game->player->stat->speed;
    fill_stats(stats, stats_values, game);
}