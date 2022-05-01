/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** test_main_animation
*/

#include "struct_var.h"
#include "my.h"

int initialize_window(sfRenderWindow **window)
{
    sfVideoMode mode = {700, 700, 32};
    (*window) = sfRenderWindow_create(mode, "piksel", sfClose, NULL);
    if ((*window) == NULL)
        return (84);
    return (0);
}

int event_handler(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    return (0);
}

int main()
{
    sfRenderWindow *window = NULL;
    clock_data_t *main_display_clock = create_clock_data();
    animator_t *animator_test = load_animator("tests/scripts/iddle.ani");
    sfEvent event;

    if (animator_test == NULL)
        return (84);
    sfSprite_setPosition(animator_test->sprite_data->sprite, (sfVector2f){100, 100});
    animator_test->nbr_image_xy.y = 1;
    animator_test->clock_data->framerate = 1000000/10;
    set_framerate_clock_data(main_display_clock, 1000000/60);
    if (initialize_window(&window) == 84)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        drain_clock_data(main_display_clock);
        while (update_clock_data(main_display_clock)) {
            while (sfRenderWindow_pollEvent(window, &event))
                event_handler(&event, window);
            update_animator(animator_test);
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, animator_test->sprite_data->sprite, NULL);
            sfRenderWindow_display(window);
        }
    }
    return (0);
}
