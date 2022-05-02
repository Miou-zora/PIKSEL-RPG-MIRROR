/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_texts_zones
*/

#include "rpg.h"
#include "my.h"

void add_return_to_the_line(text_zone_t **text_zone, char *text_string, int i)
{
    for (; text_string[i] != '\0'; i++) {
        if (text_string[i] == ' ') {
            (*text_zone)->text_string[i] = '\n';
            return;
        }
    }
}

int set_text_strings(text_zone_t **text_zone, char *text_string)
{
    (*text_zone)->current_string = my_calloc(1, (my_strlen(text_string) + 1));
    if ((*text_zone)->current_string == NULL)
        return (84);
    (*text_zone)->current_string[0] = '\0';
    (*text_zone)->text_string = my_calloc(1, (my_strlen(text_string) + 1));
    (*text_zone)->text_string = my_strdup(text_string);
    if (my_strlen(text_string) < 110)
        return (0);
    for (int i = 110; text_string[i] != '\0'; i+= 115) {
        add_return_to_the_line(text_zone, text_string, i);
    }
    return (0);
}

int set_text_zone_variables(text_zone_t **text_zone)
{
    initialize_sprite_data(&((*text_zone)->text_zone_sprite),
    "assets/text_zone/text_zone.png", (sfVector2f){7, 7},
    (sfVector2f){120, 450});
    sfText_setFont((*text_zone)->text, (*text_zone)->font);
    sfText_setString((*text_zone)->text, (*text_zone)->current_string);
    sfText_setColor((*text_zone)->text, sfBlack);
    sfText_setPosition((*text_zone)->text, (sfVector2f){150, 750});
    sfText_setScale((*text_zone)->text, (sfVector2f){1.05, 1.05});
    return (0);
}

int create_text_zone(text_zone_t **text_zone, char *text_string)
{
    (*text_zone) = malloc(sizeof(text_zone_t));
    if ((*text_zone) == NULL)
        return (84);
    (*text_zone)->font =
    sfFont_createFromFile("assets/font/arcadeclassic/ARCADECLASSIC.TTF");
    if ((*text_zone)->font == NULL) {
        return (84);
    }
    (*text_zone)->text = sfText_create();
    if ((*text_zone)->text == NULL) {
        return (84);
    }
    if (set_text_strings(text_zone, text_string) == 84) {
        return (84);
    }
    if (set_text_zone_variables(text_zone) == 84)
        return (84);
    (*text_zone)->which_character = 0;
    (*text_zone)->enter_is_pressed = false;
    return (0);
}

void free_bubbles_text(char **bubbles)
{
    for (int i = 0; bubbles[i] != NULL; i++) {
        free(bubbles[i]);
    }
    free(bubbles);
}