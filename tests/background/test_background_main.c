/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "struct_var.h"

sprite_data_t *set_sprite(sprite_data_t *sprite)
{
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_scale(sprite->sprite, sprite->scale);
    return (sprite);
}

background_t *init_laboratory(background_t *background)
{
    background->laboratory = malloc(sizeof(laboratory_t));
    background->laboratory->sprite = malloc(sizeof(sprite_data_t));
    background->laboratory->sprite->pos = (sfVector2f){0, 0};
    background->laboratory->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    background->laboratory->sprite->scale = (sfVector2f){4, 4};
    background->laboratory->sprite->sprite = sfSprite_create();
    background->laboratory->sprite->texture = \
    sfTexture_createFromFile("assets/background/Labo.png", NULL);
    set_sprite(background->laboratory->sprite);
    return (background);
}

background_t *init_bedroom(background_t *background)
{
    background->bedroom = malloc(sizeof(bedroom_t));
    background->bedroom->sprite = malloc(sizeof(sprite_data_t));
    background->bedroom->sprite->pos = (sfVector2f){0, 0};
    background->bedroom->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    background->bedroom->sprite->scale = (sfVector2f){4, 4};
    background->bedroom->sprite->sprite = sfSprite_create();
    background->bedroom->sprite->texture = \
    sfTexture_createFromFile("assets/background/appart.png", NULL);
    set_sprite(background->bedroom->sprite);
    return (background);
}

background_t *init_town(background_t *background)
{
    background->town[FRONTGROUND] = malloc(sizeof(forest_t));
    background->town[FRONTGROUND]->sprite = malloc(sizeof(sprite_data_t));
    background->town[FRONTGROUND]->sprite->pos = (sfVector2f){0, 0};
    background->town[FRONTGROUND]->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    background->town[FRONTGROUND]->sprite->scale = (sfVector2f){4, 4};
    background->town[FRONTGROUND]->sprite->sprite = sfSprite_create();
    background->town[FRONTGROUND]->sprite->texture = \
    sfTexture_createFromFile("assets/background/city.png", NULL);
    set_sprite(background->town[FRONTGROUND]->sprite);
    background->town[MIDGROUND] = malloc(sizeof(forest_t));
    background->town[MIDGROUND]->sprite = malloc(sizeof(sprite_data_t));
    background->town[MIDGROUND]->sprite->pos = (sfVector2f){0, 0};
    background->town[MIDGROUND]->sprite->rect = (sfIntRect){0, 0, 880, 1920};
    background->town[MIDGROUND]->sprite->scale = (sfVector2f){4, 4};
    background->town[MIDGROUND]->sprite->sprite = sfSprite_create();
    background->town[MIDGROUND]->sprite->texture = \
    sfTexture_createFromFile("assets/background/light.png", NULL);
    set_sprite(background->town[MIDGROUND]->sprite);
    return (background);
}

background_t *init_forest(background_t *background)
{
    background->forest[FRONTGROUND] = malloc(sizeof(forest_t));
    background->forest[FRONTGROUND]->sprite = malloc(sizeof(sprite_data_t));
    background->forest[FRONTGROUND]->sprite->pos = (sfVector2f){0, 0};
    background->forest[FRONTGROUND]->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    background->forest[FRONTGROUND]->sprite->scale = (sfVector2f){4, 4};
    background->forest[FRONTGROUND]->sprite->sprite = sfSprite_create();
    background->forest[FRONTGROUND]->sprite->texture = \
    sfTexture_createFromFile("assets/background/Forest_back.png", NULL);
    set_sprite(background->forest[FRONTGROUND]->sprite);
    background->forest[MIDGROUND] = malloc(sizeof(forest_t));
    background->forest[MIDGROUND]->sprite = malloc(sizeof(sprite_data_t));
    background->forest[MIDGROUND]->sprite->pos = (sfVector2f){0, 100};
    background->forest[MIDGROUND]->sprite->rect = (sfIntRect){0, 0, 1080, 1920};
    background->forest[MIDGROUND]->sprite->scale = (sfVector2f){3, 3};
    background->forest[MIDGROUND]->sprite->sprite = sfSprite_create();
    background->forest[MIDGROUND]->sprite->texture = \
    sfTexture_createFromFile("assets/background/Forest_front.png", NULL);
    set_sprite(background->forest[MIDGROUND]->sprite);
    return (background);
}

int create_init_game(game_t *game)
{
    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "ennemy_test", sfResize | sfClose, NULL);
    game->background = malloc(sizeof(background_t));
    game->background->scene_background = ROOM;
    init_forest(game->background);
    init_town(game->background);
    init_bedroom(game->background);
    init_laboratory(game->background);
    game->clock = sfClock_create();
    return (0);
}

void display(game_t *game)
{
    if (game->background->scene_background == 0) {
        sfRenderWindow_drawSprite(game->window,
        game->background->bedroom->sprite->sprite, NULL);
    } else if (game->background->scene_background == 1) {
        sfRenderWindow_drawSprite(game->window,
        game->background->town[0]->sprite->sprite, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->background->town[1]->sprite->sprite, NULL);
    } else if (game->background->scene_background == 2) {
        return;
    } else if (game->background->scene_background == 3) {
        sfRenderWindow_drawSprite(game->window,
        game->background->forest[0]->sprite->sprite, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->background->forest[1]->sprite->sprite, NULL);
    } else if (game->background->scene_background == 4) {
        return;
    } else if (game->background->scene_background == 5) {
        sfRenderWindow_drawSprite(game->window,
        game->background->laboratory->sprite->sprite, NULL);
    }
    return;
}

void manage_key_pressed(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyRight) {
        if (game->background->scene_background == 0
        && game->background->bedroom->sprite->rect.left < 300) {
            game->background->bedroom->sprite->rect.left += 5;
            sfSprite_setTextureRect(game->background->bedroom->sprite->sprite,
            game->background->bedroom->sprite->rect);
        } else if (game->background->scene_background == 1) {
            game->background->town[0]->sprite->rect.left += 5;
            game->background->town[1]->sprite->rect.left += 10;
            sfSprite_setTextureRect(game->background->town[0]->sprite->sprite,
            game->background->town[0]->sprite->rect);
            sfSprite_setTextureRect(game->background->town[1]->sprite->sprite,
            game->background->town[1]->sprite->rect);
        } else if (game->background->scene_background == 2) {
            return;
        } else if (game->background->scene_background == 3) {
            sfRenderWindow_drawSprite(game->window,
            game->background->forest[0]->sprite->sprite, NULL);
            sfRenderWindow_drawSprite(game->window,
            game->background->forest[1]->sprite->sprite, NULL);
        } else if (game->background->scene_background == 4) {
            return;
        } else if (game->background->scene_background == 5) {
            sfRenderWindow_drawSprite(game->window,
            game->background->laboratory->sprite->sprite, NULL);
        }
    } else if (event.key.code == sfKeyLeft) {
        if (game->background->scene_background == 0
        && game->background->bedroom->sprite->rect.left > 0) {
            game->background->bedroom->sprite->rect.left -= 5;
            sfSprite_setTextureRect(game->background->bedroom->sprite->sprite,
            game->background->bedroom->sprite->rect);
        } else if (game->background->scene_background == 1) {
            game->background->town[0]->sprite->rect.left -= 5;
            game->background->town[1]->sprite->rect.left -= 10;
            sfSprite_setTextureRect(game->background->town[0]->sprite->sprite,
            game->background->town[0]->sprite->rect);
            sfSprite_setTextureRect(game->background->town[1]->sprite->sprite,
            game->background->town[1]->sprite->rect);
        } 
    }
}

void analyse_event(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
    }
    if (event.type == sfEvtMouseButtonPressed
    && game->background->scene_background < 5)
        game->background->scene_background += 1;
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
    sfTexture_setRepeated(game->background->forest[0]->sprite->texture, true);
    sfTexture_setRepeated(game->background->forest[1]->sprite->texture, true);
    sfTexture_setRepeated(game->background->town[0]->sprite->texture, true);
    sfTexture_setRepeated(game->background->town[1]->sprite->texture, true);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        display(game);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, &event))
            analyse_event(event, game);
        sfRenderWindow_clear(game->window, sfBlack);
    }
    sfRenderWindow_destroy(game->window);
}