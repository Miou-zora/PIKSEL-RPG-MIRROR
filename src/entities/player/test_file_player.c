/*
** EPITECH PROJECT, 2022
** test_file_player
** File description:
** test_file_player
*/

#include "struct_var.h"
#include <stdlib.h>

void create_animator()
{
    
}

void display(player_t *player)
{
    sfRenderWindow_drawSprite(player->window, player->iddle->sprite_data->sprite, NULL);
}

void create_sprite_player_iddle(player_t *player)
{
    player->iddle->sprite_data->sprite = sfSprite_create();
    player->iddle->sprite_data->texture = sfTexture_createFromFile("assets/player/Stick iddle.png", NULL);
    player->iddle->sprite_data->scale = (sfVector2f){4, 4};
    player->iddle->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->iddle->sprite_data->sprite, player->iddle->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->iddle->sprite_data->sprite, player->iddle->sprite_data->scale);
    sfSprite_setTextureRect(player->iddle->sprite_data->sprite, player->iddle->sprite_data->rect);
    player->iddle->number_image = 6;
    player->iddle->actual_image = (sfVector2i){0, 0};
    player->iddle->nbr_image_xy = (sfVector2i){6, 1};
    player->iddle->size_image = (sfVector2f){48, 48};
}

void create_sprite_player(player_t *player)
{
    create_sprite_player_iddle(player);
}

////////////////////////////////

void analyse_events(player_t *player)
{
    if (player->event.type == sfEvtClosed)
        sfRenderWindow_close(player->window);
}

int my_rpg(void)
{
    player_t *player = malloc(sizeof(player_t));
    animator_t *animator = malloc(sizeof(animator_t));
    sprite_data_t *sprite_data = malloc(sizeof(sprite_data_t));
    sfVideoMode mode = {1920, 1080, 32};

    player->window = sfRenderWindow_create(mode, "PIKSEL", sfClose | sfResize, NULL);
    player->iddle = animator;
    player->iddle->sprite_data = sprite_data;
    create_sprite_player(player);
    while (sfRenderWindow_isOpen(player->window)) {
        while (sfRenderWindow_pollEvent(player->window, &player->event))
            analyse_events(player);
        display(player);
        sfRenderWindow_display(player->window);
        sfRenderWindow_clear(player->window, sfBlack);
    }
    return (0);
}

int main()
{
    my_rpg();
    return (0);
}