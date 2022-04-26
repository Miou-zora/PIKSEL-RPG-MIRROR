/*
** EPITECH PROJECT, 2022
** test_file_player
** File description:
** test_file_player
*/

#include "struct_var.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

/////// DISPLAY SPRITE ///////

void display(player_t *player)
{
    if (player->player_mode == 0)
        sfRenderWindow_drawSprite(player->window, player->iddle->sprite_data->sprite, NULL);
    if (player->player_mode == 1)
        sfRenderWindow_drawSprite(player->window, player->walk->sprite_data->sprite, NULL);
    if (player->player_mode == 2)
        sfRenderWindow_drawSprite(player->window, player->run->sprite_data->sprite, NULL);
}

/////// CLOCK ///////

////////////// ANIMATION

void player_animation_run(player_t *player)
{
    player->run->sprite_data->rect.left += 48;
    if (player->run->sprite_data->rect.left == 576)
        player->run->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->run->sprite_data->sprite);
    sfSprite_setTextureRect(player->run->sprite_data->sprite,
    player->run->sprite_data->rect);
}

void player_animation_walk(player_t *player)
{
    player->walk->sprite_data->rect.left += 48;
    if (player->walk->sprite_data->rect.left == 288)
        player->walk->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->walk->sprite_data->sprite);
    sfSprite_setTextureRect(player->walk->sprite_data->sprite,
    player->walk->sprite_data->rect);
}


void player_animation_iddle(player_t *player)
{
    player->iddle->sprite_data->rect.left += 48;
    if (player->iddle->sprite_data->rect.left == 288)
        player->iddle->sprite_data->rect.left = 0;
    sfSprite_getTextureRect(player->iddle->sprite_data->sprite);
    sfSprite_setTextureRect(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->rect);
}

void clock_animation_player(player_t *player)
{
    player->time_anim = sfClock_getElapsedTime(player->clock_anim);
    player->seconds_anim = player->time_anim.microseconds;
    sfClock_restart(player->clock_anim);
    if (player->player_mode == 0)
        player_animation_iddle(player);
    if (player->player_mode == 1)
        player_animation_walk(player);
    if (player->player_mode == 2)
        player_animation_run(player);
    while (player->seconds_anim > 1000000.0) {
        player->seconds_anim -= 1000000.0;
    }
}

////////////// PLAYER

void update_position(player_t *player)
{
    sfSprite_getPosition(player->iddle->sprite_data->sprite);
    sfSprite_setPosition(player->iddle->sprite_data->sprite,
    player->walk->sprite_data->pos);
    sfSprite_getPosition(player->walk->sprite_data->sprite);
    sfSprite_setPosition(player->walk->sprite_data->sprite,
    player->walk->sprite_data->pos);
    sfSprite_getPosition(player->run->sprite_data->sprite);
    sfSprite_setPosition(player->run->sprite_data->sprite,
    player->walk->sprite_data->pos);
}

void move_player(player_t *player)
{
    if (player->move_up)
        player->walk->sprite_data->pos.y -= 0.5;
    if (player->move_down)
        player->walk->sprite_data->pos.y += 0.5;
    if (player->move_left)
        player->walk->sprite_data->pos.x += 0.5;
    if (player->move_right)
        player->walk->sprite_data->pos.x -= 0.5;
}

void clock_player(player_t *player)
{
    player->time_player = sfClock_getElapsedTime(player->clock_player);
    player->seconds_player = player->time_player.microseconds;
    sfClock_restart(player->clock_player);
    move_player(player);
    update_position(player);
    while (player->seconds_player > 1000000.0) {
        player->seconds_player -= 1000000.0;
    }
}

/////// CREATE SPRITE ///////

void create_sprite_player_walk(player_t *player)
{
    player->walk->sprite_data->sprite = sfSprite_create();
    player->walk->sprite_data->texture = sfTexture_createFromFile(
        "assets/player/Stick walk.png", NULL);
    player->walk->sprite_data->scale = (sfVector2f){4, 4};
    player->walk->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->walk->sprite_data->sprite,
    player->walk->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->walk->sprite_data->sprite,
    player->walk->sprite_data->scale);
    sfSprite_setTextureRect(player->walk->sprite_data->sprite,
    player->walk->sprite_data->rect);
    player->walk->number_image = 6;
    player->walk->actual_image = (sfVector2i){0, 0};
    player->walk->nbr_image_xy = (sfVector2i){6, 1};
    player->walk->size_image = (sfVector2f){48, 48};
}

void create_sprite_player_run(player_t *player)
{
    player->run->sprite_data->sprite = sfSprite_create();
    player->run->sprite_data->texture = sfTexture_createFromFile
    ("assets/player/Stick run.png", NULL);
    player->run->sprite_data->scale = (sfVector2f){4, 4};
    player->run->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->run->sprite_data->sprite,
    player->run->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->run->sprite_data->sprite,
    player->run->sprite_data->scale);
    sfSprite_setTextureRect(player->run->sprite_data->sprite,
    player->run->sprite_data->rect);
    player->run->number_image = 12;
    player->run->actual_image = (sfVector2i){0, 0};
    player->run->nbr_image_xy = (sfVector2i){12, 1};
    player->run->size_image = (sfVector2f){48, 48};
}

void create_sprite_player_iddle(player_t *player)
{
    player->iddle->sprite_data->sprite = sfSprite_create();
    player->iddle->sprite_data->texture = sfTexture_createFromFile
    ("assets/player/Stick iddle.png", NULL);
    player->iddle->sprite_data->scale = (sfVector2f){4, 4};
    player->iddle->sprite_data->rect = (sfIntRect){0, 0, 48, 48};
    sfSprite_setTexture(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->texture, sfTrue);
    sfSprite_setScale(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->scale);
    sfSprite_setTextureRect(player->iddle->sprite_data->sprite,
    player->iddle->sprite_data->rect);
    player->iddle->number_image = 6;
    player->iddle->actual_image = (sfVector2i){0, 0};
    player->iddle->nbr_image_xy = (sfVector2i){6, 1};
    player->iddle->size_image = (sfVector2f){48, 48};
}

void create_sprite_player(player_t *player)
{
    create_sprite_player_iddle(player);
    create_sprite_player_walk(player);
    create_sprite_player_run(player);
}

/////// EVENTS ///////

void key_released(player_t *player)
{
    if (player->event.type == sfEvtKeyReleased) {
        player->player_mode = 0;
        player->move_up = false;
        player->move_down = false;
        player->move_left = false;
        player->move_right = false;
    }
}

void detect_key(player_t *player)
{
    if (player->event.key.code == sfKeyZ) {
        player->player_mode = 1;
        player->move_up = true;
    }
    if (player->event.key.code == sfKeyS) {
        player->player_mode = 1;
        player->move_down = true;
    }
    if (player->event.key.code == sfKeyD) {
        player->player_mode = 1;
        player->move_left = true;
    }
    if (player->event.key.code == sfKeyQ) {
        player->player_mode = 1;
        player->move_right = true;
    }
    key_released(player);
}

void analyse_events(player_t *player)
{
    if (player->event.type == sfEvtClosed)
        sfRenderWindow_close(player->window);
    detect_key(player);
}

/////// GAME LOOP ///////

int my_rpg(void)
{
    player_t *player = malloc(sizeof(player_t));
    animator_t *animator_iddle = malloc(sizeof(animator_t));
    animator_t *animator_walk = malloc(sizeof(animator_t));
    animator_t *animator_run = malloc(sizeof(animator_t));
    sprite_data_t *sprite_data_iddle = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_walk = malloc(sizeof(sprite_data_t));
    sprite_data_t *sprite_data_run = malloc(sizeof(sprite_data_t));
    sfVideoMode mode = {1920, 1080, 32};
    player->clock_player= sfClock_create();
    player->clock_anim = sfClock_create();
    player->player_mode = 0;

    player->window = sfRenderWindow_create(mode, "PIKSEL", sfClose | sfResize, NULL);
    player->iddle = animator_iddle;
    player->iddle->sprite_data = sprite_data_iddle;
    player->walk = animator_walk;
    player->walk->sprite_data = sprite_data_walk;
    player->run = animator_run;
    player->run->sprite_data = sprite_data_run;
    create_sprite_player(player);
    while (sfRenderWindow_isOpen(player->window)) {
        while (sfRenderWindow_pollEvent(player->window, &player->event))
            analyse_events(player);
        clock_player(player);
        clock_animation_player(player);
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