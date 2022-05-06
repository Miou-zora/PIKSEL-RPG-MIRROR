/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_npc
*/

#include "my.h"
#include "struct_var.h"

bool init_quete_npc(npc_t *npc[4])
{
    npc[0] = my_calloc(1, sizeof(npc_t));
    if (npc[0] == NULL)
        return (true);
    npc[0]->sprite_data = load_sprite_data("assets/npc.png");
    if (npc[0]->sprite_data == NULL)
        return (true);
    npc[0]->sprite_data->pos = (sfVector2f){2000, 460};
    npc[0]->sprite_data->scale = (sfVector2f){0.5, 0.5};
    npc[0]->distance_à_parcourir = 520;
    npc[0]->scene = CITY;
    npc[0]->display = false;
    npc[0]->sprite_data = set_sprite(npc[0]->sprite_data);
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
    npc[1]->distance_à_parcourir = 100;
    npc[1]->scene = CITY;
    npc[1]->display = false;
    npc[1]->sprite_data = set_sprite(npc[1]->sprite_data);
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
    npc[2]->distance_à_parcourir = 50;
    npc[2]->scene = FOREST;
    npc[2]->display = false;
    npc[2]->sprite_data = set_sprite(npc[2]->sprite_data);

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
    npc[3]->distance_à_parcourir = 540;
    npc[3]->scene = FOREST;
    npc[3]->display = false;
    npc[3]->sprite_data = set_sprite(npc[3]->sprite_data);
    return (false);
}

bool init_npc(npc_t *npc[4])
{
    if (init_quete_npc(npc))
        return (true);
    if (init_city_to_forest_npc(npc))
        return (true);
    if (init_forest_to_city_npc(npc))
        return (true);
    if (init_forest_to_lab_npc(npc))
        return (true);
    return (false);
}