/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_healthbar
*/

#include "struct_var.h"
#include "my.h"

void change_color(sfUint8 *coloro, sfUint8 *colort)
{
    if ((*coloro) > 0)
        (*coloro) -= 1;
    else
        (*colort) += 1;
}

void update_fade_pixel(sfColor *color)
{
    if (color->r == 255 && color->g < 255) {
        change_color(&(color->b), &(color->g));
        return;
    } else if (color->g == 255 && color->b < 255) {
        change_color(&(color->r), &(color->b));
        return;
    } else if (color->b == 255 && color->r < 255) {
        change_color(&(color->g), &(color->r));
        return;
    }
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
        color =
        (sfColor){framebuffer->pixels[(y * framebuffer->width + x) * 4 + 0],
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
    unsigned int pos_life = enemy->stat.actual_life * enemy->healthbar->width
    / enemy->stat.health;
    bool boss = (enemy->type_enemy == BOSS ||
    enemy->type_enemy == MINI_BOSS) ?
    true : false;

    for (unsigned int y = 0; y < enemy->healthbar->height *
    enemy->healthbar->width; y++) {
        if (y % enemy->healthbar->width < pos_life)
            update_pixel(enemy->healthbar, y, boss, true);
        else
            update_pixel(enemy->healthbar, y, boss, false);
    }
}
