/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** free_text_zone
*/

#include "struct_var.h"

void free_text_zone(text_zone_t *text_zone)
{
    free(text_zone->current_string);
    sfFont_destroy(text_zone->font);
    sfSprite_destroy(text_zone->text_zone_sprite->sprite);
    sfTexture_destroy(text_zone->text_zone_sprite->texture);
    free(text_zone->text_zone_sprite);
    sfText_destroy(text_zone->text);
    sfClock_destroy(text_zone->text_clock->clocksfInt64);
    free(text_zone->text_clock);
    free(text_zone->text_string);
    free(text_zone);
}