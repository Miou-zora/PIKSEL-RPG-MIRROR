/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_settings
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

void initialize_settings_rectangle_shapes(settings_infos_t *settings_infos)
{
    for (int i = 0; i < 3; i++) {
        settings_infos->fill_rectangles[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(settings_infos->fill_rectangles[i],
        settings_infos->rectangles_positions[i * 2]);
        sfRectangleShape_setFillColor(settings_infos->fill_rectangles[i],
        sfTransparent);
        sfRectangleShape_setOutlineThickness
        (settings_infos->fill_rectangles[i], 6);
        sfRectangleShape_setOutlineColor
        (settings_infos->fill_rectangles[i],
        sfColor_fromRGB((sfUint8)52, (sfUint8)201, (sfUint8)306));
        sfRectangleShape_setSize(settings_infos->fill_rectangles[i],
        settings_infos->rectangles_sizes[i * 2]);
    }
}

int initialize_settings_rectangles(settings_infos_t **settings_infos)
{
    (*settings_infos) = malloc(sizeof(settings_infos_t));
    (*settings_infos)->fill_rectangles =
    malloc(sizeof(sfRectangleShape *) * 3);
    if ((*settings_infos)->fill_rectangles == NULL)
        return (84);
    (*settings_infos)->rectangles_positions =
    initialize_positions
    ("1100 295 1340 295 1100 535 1340 535 1100 775 1250 775 1400 775", 7);
    (*settings_infos)->rectangles_sizes = initialize_positions
    ("220 135 245 135 220 135 245 135 140 135 140 135 185 135", 7);
    initialize_settings_rectangle_shapes((*settings_infos));
    return (0);
}

int initialize_settings(scene_t **settings_scene, scene_t *old_scene)
{
    sfRenderWindow_clear(old_scene->window, sfBlack);
    (*settings_scene) = malloc(sizeof(scene_t));

    if ((*settings_scene) == NULL)
        return (84);
    if (initialize_sprite_data(&((*settings_scene)->background),
    "assets/menu/settings.png", (sfVector2f){8, 8},
    (sfVector2f){0, 0}) == 84)
        return (84);
    (*settings_scene)->window = old_scene->window;
    initialize_hitbox(&((*settings_scene)->select_zone),
    "365 295 365 535 365 775 90 830", 4);
    (*settings_scene)->zone_name = "settings";
    (*settings_scene)->select_zone->current_pos = 0;
    initialize_settings_rectangles(&((*settings_scene))->settings);
    return (0);
}