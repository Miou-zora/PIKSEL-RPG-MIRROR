/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** handle_loot
*/

#include "struct_var.h"
#include "my.h"

void destroy_loot(loot_t *loot)
{
    if (loot->armor_or_weapon == 0) {
        destroy_armor(&loot->armor);
    } else if (loot->armor_or_weapon == 1) {
        destroy_weapon(&loot->weapon);
    }
}

void get_loot(game_t *game)
{
    sfVector2f loot_pos;

    for (int i = 0; game->background->loot[i]->armor_or_weapon != 2; i++) {
        if (game->background->loot[i]->armor_or_weapon == 3)
            continue;
        loot_pos.x = game->background->loot[i]->position.x - 100;
        loot_pos.y = game->background->loot[i]->position.y - 200;
        if (game->player->pos.x >= loot_pos.x - 100 &&
        game->player->pos.x <= loot_pos.x + 100 &&
        game->player->pos.y >= loot_pos.y - 100 &&
        game->player->pos.y <= loot_pos.y + 100) {
            add_loot_to_inventory(game->player->inventory,
            game->background->loot[i], game->player);
            return;
        }
    }
}

void move_loot(loot_t **loot, int to_move)
{
    for (int i = 0; loot[i]->armor_or_weapon != 2; i++) {
        loot[i]->position.x += to_move;
        if (loot[i]->armor_or_weapon == 0) {
            sfSprite_move(loot[i]->armor->sprite_data->sprite,
            (sfVector2f){to_move, 0});
        }
        if (loot[i]->armor_or_weapon == 1) {
            sfSprite_move(loot[i]->weapon->sprite_data->sprite,
            (sfVector2f){to_move, 0});
        }
    }
}

bool init_loot(loot_t *loot[10])
{
    for (int i = 0; i < 10; i++) {
        loot[i] = malloc(sizeof(loot_t));
        if (loot[i] == NULL)
            return (true);
        loot[i]->armor_or_weapon = 2;
    }
    return (false);
}

void destroy_game(game_t *game)
{
    kill_all_enemy(&game->enemies_list, game->player,
    (loot_t **)&(game->background->loot));
    sfMusic_destroy(game->sound_music->music);
    sfSound_destroy(game->sound_music->damage);
    sfSound_destroy(game->sound_music->terry);
    sfSound_destroy(game->sound_music->teleport);
    sfRenderWindow_close(game->window);
}