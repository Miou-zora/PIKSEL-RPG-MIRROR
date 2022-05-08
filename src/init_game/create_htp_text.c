/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_htp_text
*/

#include "struct_var.h"

bool create_how_to_play(text_zone_t **text_zone)
{
    (*text_zone) = malloc(sizeof(text_zone_t));
    if ((*text_zone) == NULL)
        return (true);
    (*text_zone)->font =
    sfFont_createFromFile("assets/font/font.ttf");
    if ((*text_zone)->font == NULL) {
        return (true);
    }
    (*text_zone)->text = sfText_create();
    if ((*text_zone)->text == NULL) {
        return (true);
    }
    return (false);
}