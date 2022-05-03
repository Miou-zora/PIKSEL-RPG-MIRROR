/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update
*/

#include "struct_var.h"
#include "my.h"

//UTILISER L'AUTRE DISPLAY ET UPDATE

int analyse_events_menu(sfEvent *event, scene_t *scene,
settings_t **settings, dialogues_t **dialogue)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(scene->window);
    }
    if (event->type == sfEvtKeyPressed &&
    (my_strcmp(scene->zone_name, "menu") == 0 ||
    my_strcmp(scene->zone_name, "settings") == 0))
        if (change_menu(event, scene, &(*settings), dialogue) == 84)
            return (84);
    return (0);
}

void go_to_next_dialogue(dialogues_t **dialogue, int i)
{
    free_text_zone((*dialogue)->text_zone);
    (*dialogue) = (*dialogue)->next[i];
    sfClock_restart((*dialogue)->text_zone->text_clock->clocksfInt64);
}

void handle_dialogue_keys(sfEvent *event, dialogues_t **dialogue)
{
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace) {
        (*dialogue)->text_zone->enter_is_pressed = true;
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyUp &&
    (*dialogue)->next != NULL) {
        go_to_next_dialogue(dialogue, 0);
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyDown
    && (*dialogue)->next != NULL && (*dialogue)->next[1] != NULL) {
        go_to_next_dialogue(dialogue, 1);
    }
}

void update_menu(scene_t *menu, settings_t *settings,
sfEvent *event, dialogues_t **dialogue)
{
    while (sfRenderWindow_pollEvent(menu->window, event)) {
        analyse_events_menu(event, menu, &settings, dialogue);
        if (my_strcmp(menu->zone_name, "game") == 0)
            handle_dialogue_keys(event, dialogue);
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
