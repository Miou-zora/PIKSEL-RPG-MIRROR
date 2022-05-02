/*
** EPITECH PROJECT, 2022
** events
** File description:
** events
*/

#include "struct_var.h"

void analyse_events(cinematic_t *cinematic)
{
    if (cinematic->event.type == sfEvtClosed)
        sfRenderWindow_close(cinematic->window);
}