/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_npc_text_zone
*/

#include "struct_var.h"

bool create_npc_zero_text(npc_t *npc)
{
    if (create_text_zone(&npc->dialogue,
    "                                                                        "
    "                                        "
    "                           Find the thief and take revenge !!        "
    "                                                \n\n\n                   "
    "                                                                        "
    "                      press f to continue") == 84)
        return (true);
    npc->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc->dialogue->text_clock, 0.03);
    return (false);
}

bool create_npc_one_text(npc_t *npc)
{
    if (create_text_zone(&npc->dialogue,
    "                                                                        "
    "                                        "
    "                           You will be teleported in the forest        "
    "                                                \n\n\n                   "
    "                                                                         "
    "                     press f to continue") == 84)
        return (true);
    npc->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc->dialogue->text_clock, 0.03);
    return (false);
}

bool create_npc_two_text(npc_t *npc)
{
    if (create_text_zone(&npc->dialogue,
    "                                                                        "
    "                                        "
    "                           You will be teleported in the city        "
    "                                                \n\n\n                   "
    "                                                                         "
    "                     press f to continue") == 84)
        return (true);
    npc->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc->dialogue->text_clock, 0.03);
    return (false);
}

bool create_npc_three_text(npc_t *npc)
{
    if (create_text_zone(&npc->dialogue,
    "                                                                        "
    "                                        "
    "                           You will be teleported in the lab        "
    "                                                \n\n\n                   "
    "                                                                        "
    "                      press f to continue") == 84)
        return (true);
    npc->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc->dialogue->text_clock, 0.03);
    return (false);
}

bool create_npc_four_text(npc_t *npc)
{
    if (create_text_zone(&npc->dialogue,
    "                                                                        "
"                                        "
"                           Good job you have make your revenge :)        "
"                                                \n\n\n                     "
"                                                                        "
"                    press f to continue") == 84)
        return (true);
    npc->dialogue->text_clock = create_clock_data();
    set_framerate_clock_data(npc->dialogue->text_clock, 0.03);
    return (false);
}
