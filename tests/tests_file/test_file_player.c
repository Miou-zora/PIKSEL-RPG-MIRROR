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

int detect_if_key_pressed(player_t *player)
{
    if (player->move_up == false && player->move_down == false &&
    player->move_left == false && player->move_right == false)
        return (1);
    return (0);
}

/////// DISPLAY SPRITE ///////

void display(player_t *player)
{
    if (detect_if_key_pressed(player) == 1)
        sfRenderWindow_drawSprite(player->window, player->iddle->sprite_data->sprite, NULL);
    if (player->player_mode == 1 && detect_if_key_pressed(player) == 0)
        sfRenderWindow_drawSprite(player->window, player->walk->sprite_data->sprite, NULL);
    if (player->player_mode == 2 && detect_if_key_pressed(player) == 0)
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
    player->anim->time = sfClock_getElapsedTime(player->anim->clock);
    player->anim->seconds = player->anim->time.microseconds / 1000000.0;
    if (player->anim->seconds > 0.08) {
        if (detect_if_key_pressed(player) == 1)
            player_animation_iddle(player);
        if (player->player_mode == 1 && detect_if_key_pressed(player) == 0)
            player_animation_walk(player);
        if (player->player_mode == 2 && detect_if_key_pressed(player) == 0)
            player_animation_run(player);
        sfClock_restart(player->anim->clock);
    }
}

////////////// PLAYER

void update_position(player_t *player)
{
    sfSprite_setPosition(player->run->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->walk->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->iddle->sprite_data->sprite, player->pos);
}

void move_player_walk(player_t *player)
{
    if (player->move_up == true && player->player_mode == 1)
        player->pos.y -= 0.5;
    if (player->move_down == true && player->player_mode == 1)
        player->pos.y += 0.5;
    if (player->move_left == true && player->player_mode == 1)
        player->pos.x += 0.5;
    if (player->move_right == true && player->player_mode == 1)
        player->pos.x -= 0.5;
}

void move_player_run(player_t *player)
{
    if (player->move_up == true && player->player_mode == 2)
        player->pos.y -= 1;
    if (player->move_down == true && player->player_mode == 2)
        player->pos.y += 1;
    if (player->move_left == true && player->player_mode == 2)
        player->pos.x += 1;
    if (player->move_right == true && player->player_mode == 2)
        player->pos.x -= 1;
}

void clock_player(player_t *player)
{
    player->player->time = sfClock_getElapsedTime(player->player->clock);
    player->player->seconds = player->player->time.microseconds;
    sfClock_restart(player->player->clock);
    move_player_walk(player);
    move_player_run(player);
    update_position(player);
    while (player->player->seconds > 1000000.0) {
        player->player->seconds -= 1000000.0;
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

void key_run(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        player->player_mode = 2;
    else
        player->player_mode = 1;

    if (player->player_mode == 2) {
        player->player_walk = false;
        player->player_run = true;
    } else if (player->player_mode == 1) {
        player->player_walk = true;
        player->player_run = false;
    }
}

void detect_key(player_t *player)
{
    key_run(player);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        player->move_up = true;
    else
        player->move_up = false;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        player->move_down = true;
    else
        player->move_down = false;
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        player->move_left = true;
        if (player->player_mode == 1)
            player->walk->sprite_data->scale = (sfVector2f){4, 4};
        else if (player->player_mode == 2)
            player->run->sprite_data->scale = (sfVector2f){4, 4};
    } else
        player->move_left = false;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        player->move_right = true;
        if (player->player_mode == 1)
            player->walk->sprite_data->scale = (sfVector2f){-4, 4};
        else if (player->player_mode == 2)
            player->run->sprite_data->scale = (sfVector2f){-4, 4};
    } else
        player->move_right = false;
    sfSprite_setScale(player->walk->sprite_data->sprite, player->walk->sprite_data->scale);
    sfSprite_setScale(player->run->sprite_data->sprite, player->run->sprite_data->scale);
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
    clock_player_t *struct_clock_player = malloc(sizeof(clock_player_t));
    clock_player_t *struct_clock_animator = malloc(sizeof(clock_player_t));
    sfVideoMode mode = {1920, 1080, 32};

    player->window = sfRenderWindow_create(mode, "PIKSEL", sfClose | sfResize, NULL);
    player->iddle = animator_iddle;
    player->iddle->sprite_data = sprite_data_iddle;
    player->walk = animator_walk;
    player->walk->sprite_data = sprite_data_walk;
    player->run = animator_run;
    player->run->sprite_data = sprite_data_run;
    player->player = struct_clock_player;
    player->anim = struct_clock_animator;

    player->player->clock = sfClock_create();
    player->anim->clock = sfClock_create();
    player->player_walk = false;
    player->player_run = false;
    player->player_mode = 1;
    player->pos = (sfVector2f){0, 0};

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