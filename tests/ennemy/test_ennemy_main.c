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
    game->sprite = malloc(sizeof(sprite_data_t));
    game->sprite->texture =
    sfTexture_createFromFile("assets/ennemy/wolf.png", NULL);
    game->sprite->sprite = sfSprite_create();
    game->sprite->pos = (sfVector2f){250, 250};
    game->sprite->scale = (sfVector2f){1.5, 1.5};
    game->sprite->rect = (sfIntRect){0, 0, 145, 120};
}

int initialize_var(game_t *game)
{
    game->window = sfRenderWindow_create((sfVideoMode){1080, 1920, 32},
    "ennemy_test", sfResize | sfClose, NULL);
    game->pos[0] = 0;
    game->pos[1] = 0;
    init_sprite(game);
    return (0);
}

void display(game_t *game)
{
    
    sfRenderWindow_drawSprite(game->window, game->sprite->sprite, NULL);
    return;
}

void manage_mouse_click(sfMouseButtonEvent mouseButton, game_t *game)
{
    game->pos[0] = mouseButton.x;
    game->pos[1] = mouseButton.y;
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

int main(void)
{
    sfEvent event;
    game_t *game = malloc(sizeof(game_t));

    if (initialize_var(game) == 84)
        return (84);
    sfSprite_setPosition(game->sprite->sprite, game->sprite->pos);
    sfSprite_setTexture(game->sprite->sprite, game->sprite->texture, sfTrue);
    sfSprite_setTextureRect(game->sprite->sprite, game->sprite->rect);
    sfSprite_scale(game->sprite->sprite, game->sprite->scale);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        display(game);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, &event))
            analyse_event(event, game);
        sfRenderWindow_clear(game->window, sfBlack);
        my_printf("x = %i, y = %i\n", game->pos[0], game->pos[1]);
    }
}