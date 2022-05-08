/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_healthbar
*/

#include "struct_var.h"
#include "my.h"

void update_fade_pixel(sfColor *color)
{
    if (color->r == 255 && color->g < 255) {
        if (color->b > 0)
            color->b -= 1;
        else
            color->g += 1;
    } else if (color->g == 255 && color->b < 255) {
        if (color->r > 0)
            color->r -= 1;
        else
            color->b += 1;
    } else if (color->b == 255 && color->r < 255) {
        if (color->g > 0)
            color->g -= 1;
        else
            color->r += 1;
    } else
        color->r += 1;
}

void update_pixel(framebuffer_t *framebuffer, unsigned int j,
bool boss, bool is_life)
{
    int y = j / framebuffer->width;
    int x = j % framebuffer->width;
    sfColor color = {(is_life) ? 254 : 0, 0, 0, (is_life) ?
    254 : 30};

    if (boss) {
        color = (sfColor){framebuffer->pixels[(y * framebuffer->width + x) * 4 + 0],
        framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1],
        framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2],
        (is_life) ? 254 : 30};
        update_fade_pixel(&color);
    }
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 0] = color.r;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1] = color.g;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2] = color.b;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 3] = color.a;
}

void update_healthbar(enemy_t *enemy)
{
    unsigned int pos_life = enemy->actual_animator->sprite_data->scale.x *
    enemy->stat.actual_life * enemy->healthbar->width / enemy->stat.health;
    bool boss = (enemy->type_enemy == BOSS || enemy->type_enemy == MINI_BOSS) ?
    true : false;

    for (unsigned int y = 0; y < enemy->healthbar->height * enemy->healthbar->width; y++) {
        if (y % enemy->healthbar->width < pos_life)
            update_pixel(enemy->healthbar, y, boss, true);
        else
            update_pixel(enemy->healthbar, y, boss, false);
    }
}
