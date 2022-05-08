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

void fill_stats(display_stat_t *to_display, sfRenderWindow *window)
{
    for (int i = 0; i < 5; i++) {
        to_display->stats[i][0] = '\0';
        to_display->stats[i] = put_in_str(to_display->stats_values[i],
        to_display->stats[i]);
        sfText_setString(to_display->text[i], to_display->stats[i]);
        sfText_setScale(to_display->text[i], (sfVector2f){2, 2});
        sfText_setColor(to_display->text[i], sfGreen);
    }
    sfText_setPosition(to_display->text[0], (sfVector2f){200, 20});
    sfText_setPosition(to_display->text[1], (sfVector2f){550, 20});
    sfText_setPosition(to_display->text[2], (sfVector2f){900, 20});
    sfText_setPosition(to_display->text[3], (sfVector2f){1400, 20});
    sfText_setPosition(to_display->text[4], (sfVector2f){1800, 20});
    for (int i = 0; i < 5; i++) {
        sfRenderWindow_drawText(window, to_display->text[i], NULL);
    }
}

void display_stats(game_t *game)
{
    game->player->stat->to_display->stats_values[0] =
    game->player->stat->level;
    game->player->stat->to_display->stats_values[1] = game->player->stat->xp;
    game->player->stat->to_display->stats_values[2] =
    game->player->stat->actual_life;
    game->player->stat->to_display->stats_values[3] =
    game->player->stat->armor;
    game->player->stat->to_display->stats_values[4] =
    game->player->stat->speed;
    fill_stats(game->player->stat->to_display, game->window);
}