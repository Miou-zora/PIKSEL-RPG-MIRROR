/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update_healthbar
*/

#include "struct_var.h"
#include "my.h"

void update_pixel(framebuffer_t *framebuffer, unsigned int j,
bool boss, bool is_life)
{
    int y = j / framebuffer->width;
    int x = j % framebuffer->width;
    (void)boss;

    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 0] = (is_life) ?
    254 : 0;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1] = 0;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2] = 0;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 3] = (is_life) ?
    254 : 30;
}

void update_healthbar(enemy_t *enemy)
{
    unsigned int pos_life = enemy->stat.actual_life * enemy->healthbar->width /
    enemy->stat.health;
    (void)pos_life;

    for (unsigned int y = 0; y < enemy->healthbar->height * enemy->healthbar->width; y++) {
        if (y % enemy->healthbar->width < pos_life) {
            update_pixel(enemy->healthbar, y, false, true);
        } else {
            update_pixel(enemy->healthbar, y, false, false);
        }
    }
}
