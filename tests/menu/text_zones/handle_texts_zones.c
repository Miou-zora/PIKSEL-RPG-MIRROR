/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_texts_zones
*/

#include "rpg.h"

void create_text_zone(scene_t **scene,
text_zone_t **text_zone, char *text_string)
{
    (*text_zone) = malloc(sizeof(text_zone_t));
    (*text_zone)->font = sfFont_createFromFile("assets/font/Pixeled.ttf");
    (*text_zone)->text = sfText_create();
    (*text_zone)->text_string = malloc(sizeof(char) * my_strlen(text_string));
    (*text_zone)->text_string = my_strdup(text_string);
    (*text_zone)->zone = sfRectangleShape_create();
    sfText_setFont((*text_zone)->text, (*text_zone)->font);
    sfText_setString((*text_zone)->text, (*text_zone)->text_string);
    sfRenderWindow_drawText((*scene)->window, (*text_zone)->text, NULL);
    
}