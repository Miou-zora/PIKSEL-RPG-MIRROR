/*
** EPITECH PROJECT, 2022
** events
** File description:
** events
*/

#include "struct_var.h"
#include <stdio.h>
#include "my.h"

void skip_cinematic(cinematic_t *cinematic)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        my_putchar('a');
        cinematic->walk = cinematic->walk;
    }
}

void analyse_events(cinematic_t *cinematic)
{
    if (cinematic->event.type == sfEvtClosed)
        sfRenderWindow_close(cinematic->window);
    skip_cinematic(cinematic);
}