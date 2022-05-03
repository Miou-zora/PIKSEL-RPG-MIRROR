/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_how_to_play
*/

#include "struct_var.h"

void update_how_to_play(menu_t *menu)
{
    if (menu->how_to_play_mode == true)
        drain_clock_data(menu->how_to_play->text_clock);
    while (menu->how_to_play_mode == true &&
    update_clock_data(menu->how_to_play->text_clock)) {
        if (display_one_more_char(&menu->how_to_play)
        == false) {
            menu->how_to_play_mode = false;
        }
    }
}