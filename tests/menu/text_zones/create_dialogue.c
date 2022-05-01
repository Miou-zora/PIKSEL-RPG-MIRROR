/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_dialogue
*/

#include "rpg.h"

int create_dialogue_bubble(dialogues_t **bubble, char *string)
{
    (*bubble) = malloc(sizeof(dialogues_t));
    if ((*bubble) == NULL)
        return (84);
    if (create_text_zone(&((*bubble)->text_zone), string) == 84) {
        return (84);
    }
    if (initialize_clock(&((*bubble)->text_zone->text_clock)) == 84) {
        return (84);
    }
    return (0);
}

int create_each_bubble_of_monologue(dialogues_t **dialogue,
char **bubbles, int i)
{
    (*dialogue)->next = malloc(sizeof(dialogues_t *) * 2);
    (*dialogue)->next[1] = NULL;
    if ((*dialogue)->next == NULL)
        return (84);
    if (create_dialogue_bubble(&((*dialogue)->next[0]), bubbles[i]) == 84)
        return (84);
    (*dialogue)->next[0]->next = NULL;
    if (bubbles[i + 1] != NULL)
        create_each_bubble_of_monologue(&((*dialogue)->next[0]),
        bubbles, i + 1);
    return (0);
}

int create_dialogue_list(dialogues_t **dialogue, char *path_to_file,
int question_or_monologue)
{
    char **bubbles = get_data_from_file(path_to_file);
    if (create_dialogue_bubble(dialogue, bubbles[0]) == 84)
        return (84);
    if (question_or_monologue == 0) {
        (*dialogue)->next = malloc(sizeof(dialogues_t *) * 2);
        if ((*dialogue)->next == NULL)
            return (84);
        if (create_dialogue_bubble(&((*dialogue)->next[0]), bubbles[1]) == 84)
            return (84);
        (*dialogue)->next[0]->next = NULL;
        if (create_dialogue_bubble(&((*dialogue)->next[1]), bubbles[2]) == 84)
            return (84);
        (*dialogue)->next[1]->next = NULL;
        return (0);
    } else {
        if (create_each_bubble_of_monologue(dialogue, bubbles, 1) == 84)
            return (84);
        return (0);
    }
}