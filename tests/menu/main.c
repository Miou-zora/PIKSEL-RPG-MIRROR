/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "rpg.h"

int analyse_events(sfEvent *event, scene_t *scene, settings_t **settings)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(scene->window);
    }
    if (event->type == sfEvtKeyPressed)
        if (change_menu(event, scene, &(*settings)) == 84)
            return (84);
    return (0);
}

void update(scene_t *menu, settings_t *settings, sfEvent event)
{
    while (sfRenderWindow_pollEvent(menu->window, &event))
        analyse_events(&event, menu, &settings);
    sfRenderWindow_clear(menu->window, sfBlack);
}

void update_main_clock(clock_data_t *principal_clock)
{
    principal_clock->currElapsedTime =
    sfClock_restart(principal_clock->clocksfInt64);
    principal_clock->elapsed_time +=
    principal_clock->currElapsedTime.microseconds;
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
    while (sfRenderWindow_isOpen(menu->window)) {
        update_main_clock(principal_clock);
        while (principal_clock->elapsed_time > 10000) {
            principal_clock->elapsed_time -= 10000;
            update(menu, settings, event);
            display(menu);
        }
    }
    return (0);
}

int main(void)
{
    if (my_rpg() == 84)
        return (84);
}