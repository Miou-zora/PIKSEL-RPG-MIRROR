/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_menu
*/

#include "struct_var.h"
#include "my.h"

int initialize_settings_values(settings_t **settings, scene_t **scene)
{
    (*settings) = malloc(sizeof(settings_t));
    if ((*settings) == NULL)
        return (84);
    my_putstr((*scene)->zone_name);
    (*settings)->fps = 60;
    (*settings)->sound = true;
    (*settings)->music = true;
    return (0);
}

void initialize_settings_rectangle_shapes(menu_t *menu)
{
    for (int i = 0; i < 3; i++) {
        menu->settings_rectangles[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(menu->settings_rectangles[i],
        menu->rectangles_positions[i * 2]);
        sfRectangleShape_setFillColor(menu->settings_rectangles[i],
        sfTransparent);
        sfRectangleShape_setOutlineThickness
        (menu->settings_rectangles[i], 6);
        sfRectangleShape_setOutlineColor
        (menu->settings_rectangles[i],
        sfColor_fromRGB((sfUint8)52, (sfUint8)201, (sfUint8)306));
        sfRectangleShape_setSize(menu->settings_rectangles[i],
        menu->rectangles_sizes[i * 2]);
    }
}

int initialize_settings_rectangles(menu_t *menu)
{
    menu->settings_rectangles = my_calloc(7, sizeof(sfRectangleShape *));
    if (menu->settings_rectangles == NULL)
        return (84);
    menu->rectangles_positions = initialize_positions
    ("1100 295 1340 295 1100 535 1340 535 1100 775 1250 775 1400 775", 7);
    menu->rectangles_sizes = initialize_positions
    ("220 135 245 135 220 135 245 135 140 135 140 135 185 135", 7);
    initialize_settings_rectangle_shapes(menu);
    my_putstr("salut emc");
    return (0);
}

bool initialize_menu(menu_t **menu)
{
    (*menu) = my_calloc(1, sizeof(menu_t));
    if ((*menu) == NULL)
        return (true);
    (*menu)->sprite = load_sprite_data("assets/menu/menu.png");
    sfSprite_setScale((*menu)->sprite->sprite,
    (sfVector2f){8, 8});
    sfSprite_setPosition((*menu)->sprite->sprite,
    (sfVector2f){0, 0});
    return (false);
}