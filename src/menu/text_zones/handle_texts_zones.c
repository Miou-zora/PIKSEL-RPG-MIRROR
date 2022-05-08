/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_texts_zones
*/

#include "my.h"
#include "struct_var.h"
#include <stdlib.h>

/////////////////////////////////  5 if

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
    (*text_zone)->text_string = my_strdup(text_string);
    if (my_strlen(text_string) < 110)
        return (0);
    for (int i = 110; text_string[i] != '\0'; i += 115) {
        add_return_to_the_line(text_zone, text_string, i);
    }
    return (0);
}

int set_text_zone_variables(text_zone_t **text_zone)
{
    (*text_zone)->text_zone_sprite =
    load_sprite_data("assets/text_zone/text_zone.png");
    if ((*text_zone)->text_zone_sprite == NULL)
        return (84);
    sfSprite_setPosition((*text_zone)->text_zone_sprite->sprite,
    (sfVector2f){120, 450});
    sfSprite_setScale((*text_zone)->text_zone_sprite->sprite,
    (sfVector2f){7, 7});
    sfText_setFont((*text_zone)->text, (*text_zone)->font);
    sfText_setString((*text_zone)->text, (*text_zone)->current_string);
    sfText_setColor((*text_zone)->text, sfBlack);
    sfText_setPosition((*text_zone)->text, (sfVector2f){150, 750});
    sfText_setScale((*text_zone)->text, (sfVector2f){1.05, 1.05});
    return (0);
}

void free_bubbles_text(char **bubbles)
{
    for (int i = 0; bubbles[i] != NULL; i++) {
        free(bubbles[i]);
    }
    free(bubbles);
}
