/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "rpg.h"
#include "struct_var.h"

void init_sprite(game_t *game)
{
    game->ennemy = malloc(sizeof(ennemy_t));
    game->ennemy->sprite = malloc(sizeof(ennemy_sprite_t));
    game->ennemy->sprite->max_left = 580;
    game->ennemy->sprite->clock = sfClock_create();
    game->ennemy->sprite->sprite_data = malloc(sizeof(sprite_data_t));
    game->ennemy->sprite->sprite_data->texture =
    sfTexture_createFromFile("assets/ennemy/wolf.png", NULL);
    game->ennemy->sprite->sprite_data->sprite = sfSprite_create();
    game->ennemy->sprite->sprite_data->pos = (sfVector2f){250, 250};
    game->ennemy->sprite->sprite_data->scale = (sfVector2f){1.5, 1.5};
    game->ennemy->sprite->sprite_data->rect = (sfIntRect){0, 0, 145, 115};
}

int initialize_var(game_t *game)
{
    game->window = sfRenderWindow_create((sfVideoMode){1080, 1920, 32},
    "ennemy_test", sfResize | sfClose, NULL);
    game->click[0] = 1;
    game->click[1] = 1;
    game->distance[0] = 1;
    game->distance[1] = 1;
    init_sprite(game);
    game->clock = sfClock_create();
    return (0);
}

void display(game_t *game)
{
    
    sfRenderWindow_drawSprite(game->window, game->ennemy->sprite->sprite_data->sprite, NULL);
    return;
}

void manage_mouse_click(sfMouseButtonEvent mouseButton, game_t *game)
{
    game->click[0] = mouseButton.x;
    game->click[1] = mouseButton.y;
    game->distance[0] = (int)(game->ennemy->sprite->sprite_data->pos.x - game->click[0]);
    game->distance[1] = (int)(game->ennemy->sprite->sprite_data->pos.y - game->click[1]);
}


void analyse_event(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
    }
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, game);
    return;
}

ennemy_t *move_texture(ennemy_t *ennemy, int left, int height, sfClock *clock)
{
    int time = sfClock_getElapsedTime(clock).microseconds;

    
    if (time > 100000) {
        ennemy->sprite->sprite_data->rect.top = height;
        if (ennemy->sprite->max_left >= ennemy->sprite->sprite_data->rect.left + left) {
            ennemy->sprite->sprite_data->rect.left += left;
        } else {
            ennemy->sprite->sprite_data->rect.left = 0;
        }
        sfSprite_setTextureRect(ennemy->sprite->sprite_data->sprite,
        ennemy->sprite->sprite_data->rect);
        sfClock_restart(clock);
    }
    return (ennemy);
}

ennemy_t *move_ennemy(sfClock *clock, ennemy_t *ennemy, int click[2], int distance[2])
{
    int time = sfClock_getElapsedTime(clock).microseconds;
    
    if ((float)((float)time / (float)100 >= 1)) {
        if (ennemy->sprite->sprite_data->pos.x < click[0]
        || ennemy->sprite->sprite_data->pos.x > click[0]) {
            printf("%f\n", ((float)distance[0] / (float)(abs(distance[1]) + (float)abs(distance[0]))));
            ennemy->sprite->sprite_data->pos.x -= (float)distance[0] / (float)(abs(distance[1]) + (float)abs(distance[0]));
            if (distance[0] > 0)
                ennemy = move_texture(ennemy, 148, 0, ennemy->sprite->clock);
            else
                ennemy = move_texture(ennemy, 148, 115, ennemy->sprite->clock);
        }
        if (ennemy->sprite->sprite_data->pos.y < click[1]
        || ennemy->sprite->sprite_data->pos.y > click[1]) {
            ennemy->sprite->sprite_data->pos.y -= (float)distance[1] / (float)(abs(distance[1]) + (float)abs(distance[0]));
            printf("%f\n", ((float)distance[0] / (float)(abs(distance[1]) + (float)abs(distance[0]))));
        }
        sfSprite_setPosition(ennemy->sprite->sprite_data->sprite, ennemy->sprite->sprite_data->pos);
        sfClock_restart(clock);
        my_printf("test");
    }
    return (ennemy);
}

int main(void)
{
    sfEvent event;
    game_t *game = malloc(sizeof(game_t));

    if (initialize_var(game) == 84)
        return (84);
    sfSprite_setPosition(game->ennemy->sprite->sprite_data->sprite,
    game->ennemy->sprite->sprite_data->pos);
    sfSprite_setTexture(game->ennemy->sprite->sprite_data->sprite,
    game->ennemy->sprite->sprite_data->texture, sfTrue);
    sfSprite_setTextureRect(game->ennemy->sprite->sprite_data->sprite,
    game->ennemy->sprite->sprite_data->rect);
    sfSprite_scale(game->ennemy->sprite->sprite_data->sprite,
    game->ennemy->sprite->sprite_data->scale);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        display(game);
        sfRenderWindow_display(game->window);
        game->ennemy = move_ennemy(game->clock, game->ennemy, game->click, game->distance);
        while (sfRenderWindow_pollEvent(game->window, &event))
            analyse_event(event, game);
        sfRenderWindow_clear(game->window, sfBlack);
    }
}