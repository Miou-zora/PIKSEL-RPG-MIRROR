/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** init sprite and data in rpg
*/

#include "my.h"
#include "struct_var.h"

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

int create_text_zone(text_zone_t **text_zone, char *text_string)
{
    if (create_how_to_play(text_zone))
        return (84);
    if (set_text_strings(text_zone, text_string) == 84) {
        return (84);
    }
    if (set_text_zone_variables(text_zone) == 84)
        return (84);
    (*text_zone)->which_character = 0;
    (*text_zone)->enter_is_pressed = false;
    return (0);
}

int initialize_how_to_play(game_t *game)
{
    char **text_to_write = get_data_from_file("scripts/menu/how_to_play.zon");
    if (create_text_zone(&game->background->menu->how_to_play,
    text_to_write[0]) == 84)
        return (84);
    sfSprite_setScale(
    game->background->menu->how_to_play->text_zone_sprite->sprite,
    (sfVector2f){7, 22});
    sfSprite_setPosition(
    game->background->menu->how_to_play->text_zone_sprite->sprite,
    (sfVector2f){120, -700});
    game->background->menu->how_to_play->text_clock = create_clock_data();
    sfText_setPosition(game->background->menu->how_to_play->text,
    (sfVector2f){150, 250});
    game->background->menu->how_to_play->text_clock = create_clock_data();
    set_framerate_clock_data(game->background->menu->how_to_play->text_clock,
    0.05);
    return (0);
}
