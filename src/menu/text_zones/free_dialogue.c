/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** free_dialogue
*/

#include "struct_var.h"

int free_dialogue(dialogues_t **dialogue)
{
    free_text_zone((*dialogue)->text_zone);
    if ((*dialogue)->next != NULL) {
        if ((*dialogue)->next[0] != NULL)
            free_dialogue(&((*dialogue)->next[0]));
        if ((*dialogue)->next[1] != NULL)
            free_dialogue(&((*dialogue)->next[1]));
    }
    free((*dialogue));
    return (0);
}