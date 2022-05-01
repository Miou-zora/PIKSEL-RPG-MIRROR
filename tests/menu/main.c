/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "rpg.h"

int analyse_events(sfEvent *event, scene_t *scene,
settings_t **settings, dialogues_t **dialogue)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(scene->window);
    }
    if (event->type == sfEvtKeyPressed && (my_strcmp(scene->zone_name, "menu")
    == 0 || my_strcmp(scene->zone_name, "settings") == 0))
        if (change_menu(event, scene, &(*settings), dialogue) == 84)
            return (84);
    return (0);
}

void update(scene_t *menu, settings_t *settings,
sfEvent *event, dialogues_t **dialogue)
{
    while (sfRenderWindow_pollEvent(menu->window, event)) {
        analyse_events(event, menu, &settings, dialogue);
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace
        && my_strcmp(menu->zone_name, "game") == 0) {
            (*dialogue)->text_zone->enter_is_pressed = true;
        }
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyUp
        && my_strcmp(menu->zone_name, "game") == 0 &&
        (*dialogue)->next != NULL) {
            (*dialogue) = (*dialogue)->next[0];
            sfClock_restart((*dialogue)->text_zone->text_clock->clocksfInt64);
        }
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyDown
        && my_strcmp(menu->zone_name, "game") == 0 &&
        (*dialogue)->next != NULL && (*dialogue)->next[1] != NULL) {
            (*dialogue) = (*dialogue)->next[1];
            sfClock_restart((*dialogue)->text_zone->text_clock->clocksfInt64);
        }
    }
    sfRenderWindow_clear(menu->window, sfBlack);
    if (my_strcmp(menu->zone_name, "game") == 0 &&
    (*dialogue)->text_zone->text_clock->elapsed_time > 50000) {
        display_one_more_char(&((*dialogue)->text_zone));
        (*dialogue)->text_zone->text_clock->elapsed_time -= 50000;
    }
}

void update_clock(clock_data_t *clock)
{
    clock->currElapsedTime =
    sfClock_restart(clock->clocksfInt64);
    clock->elapsed_time +=
    clock->currElapsedTime.microseconds;
}

int my_rpg(void)
{
    scene_t *menu;
    sfEvent event;
    clock_data_t *principal_clock;
    settings_t *settings;
    dialogues_t *dialogue;

    if (initialize_scene(&menu, "menu", 3, true) == 84)
        return (84);
    if (initialize_clock(&principal_clock) == 84)
        return (84);
    if (initialize_settings_values(&settings, &menu) == 84)
        return (84);
    while (sfRenderWindow_isOpen(menu->window)) {
        update_clock(principal_clock);
        if (my_strcmp(menu->zone_name, "game") == 0)
            update_clock(dialogue->text_zone->text_clock);
        while (principal_clock->elapsed_time > 10000) {
            principal_clock->elapsed_time -= 10000;
            update(menu, settings, &event, &dialogue);
            display(menu, dialogue);
        }
    }
    // if (my_strcmp(menu->zone_name, "game") == 0) {
    //     free_text_zone(text_zone);
    // }
    free_game(menu, settings, principal_clock);
    return (0);
}

int main(void)
{
    if (my_rpg() == 84)
        return (84);
}