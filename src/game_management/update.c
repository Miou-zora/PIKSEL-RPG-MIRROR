/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** update
*/

#include "struct_var.h"
#include "my.h"

void update_position(player_t *player)
{
    player->hitbox.left = player->pos.x + 100;
    player->hitbox.top = player->pos.y + 280;
    sfSprite_setPosition(player->run->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->walk->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->iddle->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->sword->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->punch->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->gun->sprite_data->sprite, player->pos);
    sfSprite_setPosition(player->spear->sprite_data->sprite, player->pos);
}

void clock_player(player_t *player, game_t *game)
{
    move_player_walk(player, game);
    move_player_run(player, game);
    update_position(player);
}

void clock_animation_player(player_t *player)
{
    if (detect_if_key_pressed(player) == 1)
        player_animation_iddle(player);
    if (player->player_mode == 1 && detect_if_key_pressed(player) == 0)
        player_animation_walk(player);
    if (player->player_mode == 2 && detect_if_key_pressed(player) == 0)
        player_animation_run(player);
    if (player->attack == true && player->weapon == 1)
        player_animation_sword(player);
    if (player->attack == true && player->weapon == 2)
        player_animation_spear(player);
    if (player->attack == true && player->weapon == 3)
        player_animation_punch(player);
    if (player->attack == true && player->weapon == 4)
        player_animation_gun(player);
}


void called_clock_player(player_t *player, game_t *game)
{
    clock_player(player, game);
    drain_clock_data(player->clock_update_animator);
    while (update_clock_data(player->clock_update_animator))
        clock_animation_player(player);
}

void update(game_t *game)
{
    if (game->background->menu->how_to_play_mode == true)
        drain_clock_data(game->background->menu->how_to_play->text_clock);
    while (game->background->menu->how_to_play_mode == true &&
    update_clock_data(game->background->menu->how_to_play->text_clock)) {
        drain_clock_data(game->background->menu->how_to_play->text_clock);
        if (display_one_more_char(&game->background->menu->how_to_play)
        == false) {
            game->background->menu->how_to_play_mode = false;
        }
    }
    if (game->background->scene_background == CINEMATIC) {
        clock_cine_text(&(game->cinematic));
        call_clock_cine(game->cinematic);
    }
    update_how_to_play(game->background->menu);
    called_clock_player(game->player, game);
    update_position(game->player);
    handle_stats(game->player->stat);
}
