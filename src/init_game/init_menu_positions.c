/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** init_positions
*/

#include "struct_var.h"
#include "my.h"
#include <stdlib.h>

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