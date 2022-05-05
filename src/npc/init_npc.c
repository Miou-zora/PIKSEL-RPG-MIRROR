/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_npc
*/

#include "my.h"
#include "struct_var.h"

bool init_npc(npc_t *npc[4])
{
    npc[0] = my_calloc(1, sizeof(npc_t));

    if (npc[0] == NULL)
        return (true);
    npc[0]->sprite_data = load_sprite_data("assets/background/city.png");
    if (npc[0]->sprite_data == NULL)
        return (true);
    npc[0]->sprite_data->pos = (sfVector2f){0, 0};
    npc[0]->sprite_data->rect = (sfIntRect){0, 0, 1080, 1920};
    npc[0]->sprite_data->scale = (sfVector2f){4, 4};
    npc[0]->distance_à_parcourir = 0;
    npc[0]->scene = CITY;
    npc[0]->sprite_data = set_sprite(npc[0]->sprite_data);
    return (false);
}