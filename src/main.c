/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "struct_var.h"

int my_rpg(void)
{
    // scene_t *menu;
    // sfEvent event;
    // clock_data_t *principal_clock;
    // settings_t *settings;
    // dialogues_t *dialogue;

    // if (initialize_structures(&menu, &principal_clock, &settings) == 84)
    //     return (84);
    // while (sfRenderWindow_isOpen(menu->window)) {
    //     update_clock(principal_clock);
    //     if (my_strcmp(menu->zone_name, "game") == 0)
    //         update_clock(dialogue->text_zone->text_clock);
    //     while (principal_clock->elapsed_time > 10000) {
    //         principal_clock->elapsed_time -= 10000;
    //         update(menu, settings, &event, &dialogue);
    //         display(menu, dialogue);
    //     }
    // }
    // free_game(menu, settings, principal_clock, dialogue);
    return (0);
}

int main(void)
{
    if (my_rpg() == 84)
        return (84);
}