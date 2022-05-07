/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** display_enemy
*/

#include "struct_var.h"
#include "my.h"

void display_particle(enemy_t *enemy, sfRenderWindow *window,
framebuffer_t *framebuffer)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_create(framebuffer->width,
    framebuffer->height);

    if (enemy == NULL || sprite == NULL || texture == NULL)
        return;
    sfTexture_updateFromPixels(texture, framebuffer->pixels,
    framebuffer->width, framebuffer->width, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){enemy->pos.x -
    framebuffer->width / 2.f +
    (enemy->actual_animator->size_image.x *
    enemy->actual_animator->sprite_data->scale.x) / 2, enemy->pos.y -
    framebuffer->height / 2.f + (enemy->actual_animator->size_image.y *
    enemy->actual_animator->sprite_data->scale.y / 2)});
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_enemy(enemy_t *enemy, sfRenderWindow *window)
{
    if (enemy == NULL)
        return;
    if (enemy->actual_animator != NULL) {
        if (enemy->nest_particle != NULL) {
            display_particle(enemy, window, enemy->nest_particle->framebuffer);
        }
        sfRenderWindow_drawSprite(window,
        enemy->actual_animator->sprite_data->sprite, NULL);
    }
}

void display_enemies_list(enemies_list_t **enemies_list,
sfRenderWindow *window)
{
    enemies_list_t **cursor = enemies_list;

    while ((*cursor)->prev != NULL)
        (*cursor) = (*cursor)->prev;
    while ((*cursor) != NULL) {
        if ((*cursor)->enemy->display)
            display_enemy((*cursor)->enemy, window);
        cursor = &((*cursor)->next);
    }
}
