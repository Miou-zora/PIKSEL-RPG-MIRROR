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

void update_direction_attack(game_t *game)
{
    if (game->player->direction == false) {
        game->player->gun->sprite_data->rect.top = 48;
        game->player->sword->sprite_data->rect.top = 48;
        game->player->spear->sprite_data->rect.top = 48;
        game->player->punch->sprite_data->rect.top = 48;
    } else {
        game->player->gun->sprite_data->rect.top = 0;
        game->player->sword->sprite_data->rect.top = 0;
        game->player->spear->sprite_data->rect.top = 0;
        game->player->punch->sprite_data->rect.top = 0;
    }
    sfSprite_setTextureRect(game->player->run->sprite_data->sprite,
    game->player->gun->sprite_data->rect);
    sfSprite_setTextureRect(game->player->run->sprite_data->sprite,
    game->player->punch->sprite_data->rect);
    sfSprite_setTextureRect(game->player->run->sprite_data->sprite,
    game->player->spear->sprite_data->rect);
    sfSprite_setTextureRect(game->player->run->sprite_data->sprite,
    game->player->sword->sprite_data->rect);
}

void clock_player(player_t *player, game_t *game)
{
    if (game->background->menu->pause->display_pause == false) {
        move_player_walk(player, game);
        move_player_run(player, game);
        update_direction_attack(game);
        update_position(player);
    }
}

void clock_animation_player(player_t *player)
{
    void (*weapons_animations[4])(player_t *player) = {player_animation_sword,
    player_animation_spear, player_animation_punch, player_animation_gun};
    if (detect_if_key_pressed(player) == 1)
        player_animation_iddle(player);
    if (player->player_mode == 1 && detect_if_key_pressed(player) == 0)
        player_animation_walk(player);
    if (player->player_mode == 2 && detect_if_key_pressed(player) == 0)
        player_animation_run(player);
    if (player->attack == true)
        weapons_animations[player->weapon - 1](player);
}

void called_clock_player(player_t *player, game_t *game)
{
    clock_player(player, game);
    drain_clock_data(player->clock_update_animator);
    while (update_clock_data(player->clock_update_animator))
        clock_animation_player(player);
}

void set_update_function(game_t *game)
{
    update_enemies_list(&(game->enemies_list), game);
    update_how_to_play(game->background->menu);
    called_clock_player(game->player, game);
    update_position(game->player);
    handle_stats(game->player->stat);
    remove_loot(game->background->loot);
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
    update_npc(game);
    if (game->background->scene_background == CINEMATIC) {
        clock_cine_text(&(game->cinematic));
        call_clock_cine(game->cinematic);
    }
    set_update_function(game);
}
