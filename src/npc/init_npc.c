/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_npc
*/

#include "my.h"
#include "struct_var.h"

bool init_quest_npc(npc_t *npc[4])
{
    npc[0] = my_calloc(1, sizeof(npc_t));
    if (npc[0] == NULL)
        return (true);
    npc[0]->sprite_data = load_sprite_data("assets/npc.png");
    if (npc[0]->sprite_data == NULL)
        return (true);
    npc[0]->sprite_data->pos = (sfVector2f){2000, 460};
    npc[0]->sprite_data->scale = (sfVector2f){0.5, 0.5};
    npc[0]->distance_to_travel = 520;
    npc[0]->scene = CITY;
    npc[0]->display_text = false;
    npc[0]->display = false;
    npc[0]->sprite_data = set_sprite(npc[0]->sprite_data);
    if (create_text_zone(&npc[0]->dialogue,
    "Find the thief and take revenge !!") == 84)
        return (true);
    npc[0]->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc[0]->dialogue->text_clock, 0.03);
    return (false);
}

bool init_city_to_forest_npc(npc_t *npc[4])
{
    npc[1] = my_calloc(1, sizeof(npc_t));
    if (npc[1] == NULL)
        return (true);
    npc[1]->sprite_data = load_sprite_data("assets/npc.png");
    if (npc[1]->sprite_data == NULL)
        return (true);
    npc[1]->sprite_data->pos = (sfVector2f){2000, 460};
    npc[1]->sprite_data->scale = (sfVector2f){0.5, 0.5};
    npc[1]->distance_to_travel = 100;
    npc[1]->scene = CITY;
    npc[1]->display_text = false;
    npc[1]->display = false;
    npc[1]->sprite_data = set_sprite(npc[1]->sprite_data);
    if (create_text_zone(&npc[1]->dialogue,
    "You will be teleported in the forest") == 84)
        return (true);
    npc[1]->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc[1]->dialogue->text_clock, 0.03);
    return (false);
}

bool init_forest_to_city_npc(npc_t *npc[4])
{
    npc[2] = my_calloc(1, sizeof(npc_t));
    if (npc[2] == NULL)
        return (true);
    npc[2]->sprite_data = load_sprite_data("assets/npc.png");
    if (npc[2]->sprite_data == NULL)
        return (true);
    npc[2]->sprite_data->pos = (sfVector2f){2000, 500};
    npc[2]->sprite_data->scale = (sfVector2f){0.5, 0.5};
    npc[2]->distance_to_travel = 50;
    npc[2]->scene = FOREST;
    npc[2]->display_text = false;
    npc[2]->display = false;
    npc[2]->sprite_data = set_sprite(npc[2]->sprite_data);
    if (create_text_zone(&npc[2]->dialogue,
    "You will be teleported in the town") == 84)
        return (true);
    npc[2]->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc[2]->dialogue->text_clock, 0.03);
    return (false);
}

bool init_forest_to_lab_npc(npc_t *npc[4])
{
    npc[3] = my_calloc(1, sizeof(npc_t));
    if (npc[3] == NULL)
        return (true);
    npc[3]->sprite_data = load_sprite_data("assets/npc.png");
    if (npc[3]->sprite_data == NULL)
        return (true);
    npc[3]->sprite_data->pos = (sfVector2f){2000, 500};
    npc[3]->sprite_data->scale = (sfVector2f){0.5, 0.5};
    npc[3]->distance_to_travel = 540;
    npc[3]->scene = FOREST;
    npc[3]->display = false;
    npc[3]->display_text = false;
    npc[3]->sprite_data = set_sprite(npc[3]->sprite_data);
    if (create_text_zone(&npc[3]->dialogue,
    "You will be teleported in the lab") == 84)
        return (true);
    npc[3]->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc[3]->dialogue->text_clock, 0.03);
    return (false);
}

bool init_npc(npc_t *npc[4])
{
    if (init_quest_npc(npc))
        return (true);
    if (init_city_to_forest_npc(npc))
        return (true);
    if (init_forest_to_city_npc(npc))
        return (true);
    if (init_forest_to_lab_npc(npc))
        return (true);
    return (false);
}