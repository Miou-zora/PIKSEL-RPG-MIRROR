/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** fill_animator
*/

#include "struct_var.h"
#include <stdbool.h>
#include "my.h"

bool fill_animator_size_image(animator_t *animator, char *data)
{
    char **values = data_to_array_str(data, "/");
    int x = 0;
    int y = 0;

    if (values == NULL || get_len_array(values) != 2 || animator == NULL) {
        return (true);
    }
    x = my_getnbr(values[0]);
    y = my_getnbr(values[1]);
    if (x <= 0 || y <= 0) {
        return (true);
    }
    freen(&values);
    animator->size_image = (sfVector2f){(float)x, (float)y};
    return (false);
}

bool fill_animator_nbr_image_xy(animator_t *animator, char *data)
{
    char **values = data_to_array_str(data, "/");
    char x = 0;
    char y = 0;

    if (values == NULL || get_len_array(values) != 2 || animator == NULL) {
        return (true);
    }
    x = my_getnbr(values[0]);
    y = my_getnbr(values[1]);
    if (x <= 0 || y <= 0) {
        return (true);
    }
    freen(&values);
    animator->nbr_image_xy = (sfVector2i){x, y};
    return (false);
}

bool fill_animator_clock(animator_t *animator, char *data)
{
    int framerate = my_getnbr(data);

    if (animator == NULL)
        return (true);
    animator->clock_data = create_clock_data();
    if (animator->clock_data == NULL || framerate <= 0) {
        return (true);
    } else {
        animator->clock_data->framerate = 1000000 / my_getnbr(data);
    }
    return (false);
}

bool fill_animator_nbr_image(animator_t *animator, char *data)
{
    int nbr_image = my_getnbr(data);

    if (animator == NULL)
        return (true);
    if (nbr_image <= 0) {
        return (true);
    } else {
        animator->number_image = nbr_image;
    }
    return (false);
}

animator_t *fill_animator(animator_t *animator, char **data)
{
    bool error = false;

    if (data == NULL || get_len_array(data) != 5 || animator == NULL) {
        return (NULL);
    } else {
        animator->sprite_data = load_sprite_data(data[4]);
        error |= fill_animator_clock(animator, data[0]);
        error |= fill_animator_nbr_image_xy(animator, data[1]);
        error |= fill_animator_size_image(animator, data[3]);
        error |= fill_animator_nbr_image(animator, data[2]);
        if (error || animator->sprite_data == NULL) {
            return(NULL);
        }
        animator->sprite_data->rect.height = animator->size_image.y;
        animator->sprite_data->rect.width = animator->size_image.x;
    }
    return (animator);
}
