/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** test_main_animation
*/

#include "struct_var.h"
#include "my.h"

typedef struct keys_s keys_t;

struct keys_s {
    bool p_key;
};

int initialize_window(sfRenderWindow **window)
{
    sfVideoMode mode = {700, 700, 32};
    (*window) = sfRenderWindow_create(mode, "my_defender", sfClose, NULL);
    if ((*window) == NULL)
        return (84);
    return (0);
}

void update_keys(sfEvent *event, keys_t *keys)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyP)
            keys->p_key = true;
    }
    if (event->type == sfEvtKeyReleased) {
        if (event->key.code == sfKeyP)
            keys->p_key = false;
    }
}

int event_handler(sfEvent *event, keys_t *keys, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (event->type == sfEvtKeyPressed)
        update_keys(event, keys);
    return (0);
}

bool update_clock(clock_data_t *clock)
{
    if (clock == NULL)
        return (false);
    if (clock->elapsed_time > clock->framerate) {
        clock->elapsed_time -= clock->framerate;
        return (true);
    }
    return (false);
}

void drain_clock_data(clock_data_t *clock)
{
    if (clock == NULL)
        return;
    clock->currElapsedTime = sfClock_restart(clock->clocksfInt64);
    clock->elapsed_time += clock->currElapsedTime.microseconds;
}

void set_framerate_clock_data(clock_data_t *clock, int framerate)
{
    if (clock == NULL)
        return;
    clock->framerate = framerate;
}

void update_animator(animator_t *animator)
{
    if (animator == NULL)
        return;
    drain_clock_data(animator->clock_data);
    if (update_clock(animator->clock_data)) {
        animator->actual_image.x++;
        if (animator->actual_image.x + 1 + animator->nbr_image_xy.x * animator->actual_image.y > animator->number_image) {
            animator->actual_image.x = 0;
            animator->actual_image.y = 0;
        }
        if (animator->actual_image.x >= animator->nbr_image_xy.x) {
            animator->actual_image.x = 0;
            animator->actual_image.y++;
            if (animator->actual_image.y >= animator->nbr_image_xy.y)
                animator->actual_image.y = 0;
        }
    }
    animator->sprite_data->pos.x = animator->actual_image.x * animator->size_image.x;
    animator->sprite_data->pos.y = animator->actual_image.y * animator->size_image.y;
    animator->sprite_data->rect.top = animator->sprite_data->pos.y;
    animator->sprite_data->rect.left = animator->sprite_data->pos.x;
    animator->sprite_data->rect.height = animator->size_image.y;
    animator->sprite_data->rect.width = animator->size_image.x;
    my_printf("%d %d\n", animator->actual_image.x, animator->actual_image.y);
    sfSprite_setTextureRect(animator->sprite_data->sprite, animator->sprite_data->rect);
}

int main()
{
    keys_t keys = {false};
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
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(&event, &keys, window);
        update_animator(animator_test);
        drain_clock_data(main_display_clock);
        while (update_clock(main_display_clock)) {
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, animator_test->sprite_data->sprite, NULL);
            sfRenderWindow_display(window);
        }
    }
    return (0);
}
