/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "rpg.h"
#include "struct_var.h"

background_t *init_sprite(background_t *background)
{
    background = malloc(sizeof(background_t));
    background->forest[0] = malloc(sizeof(forest_t));
    background->forest[0]->sprite = malloc(sizeof(sprite_data_t));
    background->forest[0]->sprite->pos = (sfVector2f){0, 0};
    background->forest[0]->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    background->forest[0]->sprite->scale = (sfVector2f){1, 1};
    background->forest[0]->sprite->sprite = sfSprite_create();
    background->forest[0]->sprite->texture = \
    sfTexture_createFromFile("assets/background/Forest_back.png", NULL);
    background->forest[1]->sprite = malloc(sizeof(sprite_data_t));
    background->forest[1]->sprite->pos = (sfVector2f){0, 0};
    background->forest[1]->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    background->forest[1]->sprite->scale = (sfVector2f){1, 1};
    background->forest[1]->sprite->sprite = sfSprite_create();
    background->forest[1]->sprite->texture = \
    sfTexture_createFromFile("assets/background/Forest_front.png", NULL);
    return (background);
}

int create_init_game(game_t *game)
{
    game->window = sfRenderWindow_create((sfVideoMode){1080, 1920, 32},
    "ennemy_test", sfResize | sfClose, NULL);
    game->background = malloc(sizeof(background_t));
    game->background = init_sprite(game->background);
    game->clock = sfClock_create();
    for (int i = 0; i != 2; i++) {
        sfSprite_setPosition(game->background->forest[i]->sprite,
        game->background->forest[i]->sprite->pos);
        sfSprite_setTexture(game->background->forest[i]->sprite,
        game->background->forest[i]->sprite->texture, sfTrue);
        sfSprite_setTextureRect(game->background->forest[i]->sprite,
        game->background->forest[i]->sprite->rect);
        sfSprite_scale(game->background->forest[i]->sprite,
        game->background->forest[i]->sprite->scale);
    }
    return (0);
}

void display(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->background->forest[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->background->forest[1]->sprite, NULL);
    return;
}

void manage_key_pressed(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyRight) {
        
    } else if (event.key.code = sfKeyLeft) {

    }
}

void analyse_event(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
    }
    if (event.type == sfEvtKeyPressed) {
        manage_key_pressed(game, event);
    }
    return;
}

int main(void)
{
    sfEvent event;
    game_t *game = malloc(sizeof(game_t));

    if (create_init_game(game) == 84)
        return (84);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        display(game);
        sfRenderWindow_display(game->window);
        game->ennemy = move_ennemy(game->clock, game->ennemy, game->click, game->distance);
        while (sfRenderWindow_pollEvent(game->window, &event))
            analyse_event(event, game);
        sfRenderWindow_clear(game->window, sfBlack);
    }
    sfRenderWindow_destroy(game->window);
}