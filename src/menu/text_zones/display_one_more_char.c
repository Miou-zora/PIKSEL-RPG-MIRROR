/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_one_more_char
*/

#include "my.h"
#include "struct_var.h"

bool display_one_more_char(text_zone_t **text_zone)
{
    if ((*text_zone)->enter_is_pressed == true
    && (*text_zone)->which_character == my_strlen((*text_zone)->text_string))
        return (false);
    if ((*text_zone)->enter_is_pressed == true
    && (*text_zone)->which_character > 0)
        (*text_zone)->which_character = my_strlen((*text_zone)->text_string);
    while ((*text_zone)->text_string[(*text_zone)->which_character] == ' ') {
        (*text_zone)->which_character++;
    }
    (*text_zone)->current_string = my_strncpy((*text_zone)->current_string,
    (*text_zone)->text_string, (*text_zone)->which_character);
    if ((*text_zone)->which_character < my_strlen((*text_zone)->text_string))
        (*text_zone)->which_character++;
    sfText_setString((*text_zone)->text, (*text_zone)->current_string);
    (*text_zone)->enter_is_pressed = false;
    return (true);
}