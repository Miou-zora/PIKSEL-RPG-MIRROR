/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_texts_zones
*/

#include "rpg.h"

void create_text_zone(text_zone_t **text_zone, char *text_string)
{
    (*text_zone) = malloc(sizeof(text_zone_t));
    (*text_zone)->font = sfFont_createFromFile("assets/font/Pixeled.ttf");
    (*text_zone)->text = sfText_create();
    (*text_zone)->current_string =
    malloc(sizeof(char) * my_strlen(text_string));
    (*text_zone)->current_string[0] = '\0';
    (*text_zone)->text_string = malloc(sizeof(char) * my_strlen(text_string));
    (*text_zone)->text_string = my_strdup(text_string);
    (*text_zone)->sprite_zone = sfSprite_create();
    (*text_zone)->texture_zone =
    sfTexture_createFromFile("assets/text_zone/text_zone.png", NULL);
    sfSprite_setTexture((*text_zone)->sprite_zone,
    (*text_zone)->texture_zone, sfFalse);
    sfSprite_setPosition((*text_zone)->sprite_zone, (sfVector2f){120, 450});
    sfSprite_setScale((*text_zone)->sprite_zone, (sfVector2f){7, 7});
    sfText_setFont((*text_zone)->text, (*text_zone)->font);
    sfText_setString((*text_zone)->text, (*text_zone)->text_string);
    sfText_setColor((*text_zone)->text, sfBlack);
    sfText_setPosition((*text_zone)->text, (sfVector2f){150, 750});
    (*text_zone)->which_character = 0;
}