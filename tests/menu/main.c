/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "rpg.h"

// int my_rpg(void)
// {
//     game_t *game = malloc(sizeof(game_t));

//     if (initialize_var(game) == 84)
//         return (84);
//     while (sfRenderWindow_isOpen(game->window)) {
//         display(game);
//         set_mouse_cursor(game);
//         sfRenderWindow_display(game->window);
//         while (sfRenderWindow_pollEvent(game->window, game->event))
//             analyse_event(game);
//         sfRenderWindow_clear(game->window, sfBlack);
//     }
//     free_all(game);
//     return (0);
// }

int analyse_events(sfEvent *event, scene_t *scene, settings_t **settings)
{
    my_putstr("anayse_events : ");
    my_put_nbr((*settings)->fps);
    my_putchar('\n');
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(scene->window);
    }
    if (event->type == sfEvtKeyPressed)
        if (change_menu(event, scene, &(*settings)) == 84)
            return (84);
    return (0);
}

int my_rpg(void)
{
    scene_t *menu;
    sfEvent event;
    clock_data_t *principal_clock;
    settings_t *settings;

    if (initialize_scene(&menu, "menu", 3, true) == 84)
        return (84);
    if (initialize_clock(&principal_clock) == 84)
        return (84);
    if (initialize_settings_values(&settings, &menu) == 84)
        return (84);
    sfRenderWindow_display(menu->window);
    while (sfRenderWindow_isOpen(menu->window)) {
        principal_clock->currElapsedTime =
        sfClock_restart(principal_clock->clocksfInt64);
        principal_clock->elapsed_time +=
        principal_clock->currElapsedTime.microseconds;
        while (principal_clock->elapsed_time > 10000) {
            principal_clock->elapsed_time -= 10000;
            // set_mouse_cursor(game);
            while (sfRenderWindow_pollEvent(menu->window, &event))
                analyse_events(&event, menu, &settings);
            sfRenderWindow_clear(menu->window, sfBlack);
            display(menu);
        }
    }
    // free_all(game);
    return (0);
}

int main(void)
{
    if (my_rpg() == 84)
        return (84);
}