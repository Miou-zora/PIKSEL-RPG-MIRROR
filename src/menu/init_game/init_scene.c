/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_scene
*/

#include "rpg.h"
#include "my.h"

sfVector2f *initialize_positions(char *positions_buffer, int nb_of_zones)
{
    int pos_in_buffer = 0;
    int number = 0;
    sfVector2f *positions = malloc(sizeof(sfVector2f) * nb_of_zones);

    for (int i = 0; i < nb_of_zones; i++) {
        number = my_getnbr(&positions_buffer[pos_in_buffer]);
        positions_buffer += get_nbrlen(number) + 1;
        positions[i].x = number;
        number = my_getnbr(&positions_buffer[pos_in_buffer]);
        positions_buffer += get_nbrlen(number) + 1;
        positions[i].y = number;
    }
    return (positions);
}

void initialize_hitbox(selection_zone_t **select_zone,
char *positions_buffer, int nb_of_zones)
{
    (*select_zone) = malloc(sizeof(selection_zone_t));
    (*select_zone)->nb_of_poses = nb_of_zones;
    (*select_zone)->positions =
    initialize_positions(positions_buffer, nb_of_zones);
    (*select_zone)->current_pos = 0;
    (*select_zone)->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition((*select_zone)->hitbox,
    (*select_zone)->positions[0]);
    sfRectangleShape_setOutlineColor((*select_zone)->hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness((*select_zone)->hitbox, 4);
    sfRectangleShape_setFillColor((*select_zone)->hitbox, sfTransparent);
    sfRectangleShape_setSize((*select_zone)->hitbox, (sfVector2f){1220, 135});
}

int initialize_scene(scene_t **scene, char *zone_name,
int nb_of_zones, bool new_window)
{
    (*scene) = malloc(sizeof(scene_t));
    if ((*scene) == NULL)
        return (84);
    if (new_window == true) {
        if (initialize_window(&((*scene)->window)) == 84)
            return (84);
    }
    if (initialize_sprite_data(&((*scene)->background),
    "assets/menu/menu.png", (sfVector2f){8, 8}, (sfVector2f){0, 0}) == 84)
        return (84);
    initialize_hitbox(&((*scene)->select_zone), "365 295 365 535 365 775",
    nb_of_zones);
    (*scene)->zone_name = zone_name;
    (*scene)->settings = NULL;
    return (0);
}