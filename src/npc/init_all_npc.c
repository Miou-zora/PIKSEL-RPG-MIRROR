/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_all_npc
*/

#include "struct_var.h"

bool init_forest_npc(npc_t *npc[5])
{
    if (init_city_to_forest_npc(npc))
        return (true);
    if (init_forest_to_city_npc(npc))
        return (true);
    if (init_forest_to_lab_npc(npc))
        return (true);
    return (false);
}

bool init_npc(npc_t *npc[5])
{
    if (init_quest_npc(npc))
        return (true);
    if (init_forest_npc(npc))
        return (true);
    if (init_win_npc(npc))
        return (true);
    return (false);
}