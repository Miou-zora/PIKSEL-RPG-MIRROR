/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** fill_armor
*/

#include "struct_var.h"
#include "my.h"

armor_t *fill_armor(armor_t *armor, char **data)
{
    if (data == NULL || get_len_array(data) != 8 || armor == NULL) {
        return (NULL);
    } else {
        armor->name = my_strdup(data[0]);
        if (armor->name == NULL) {
            return (NULL);
        }
        armor->sprite_data = load_sprite_data(data[6]);
        if (armor->sprite_data == NULL) {
            freen((void **)&(armor->name));
            return (NULL);
        }
        return (armor);
    }
}