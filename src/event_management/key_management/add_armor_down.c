/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** add_armor_down
*/

#include "struct_var.h"
#include "my.h"

void add_pant_pos(loot_t **loot, sfVector2f *pos, armor_t *temp,
sfVector2f *scale)
{
    if (temp != NULL) {
        (*loot)->armor = temp;
        (*loot)->armor_or_weapon = 0;
        pos->x += 50;
        (*loot)->position.x += 50;
        sfSprite_setPosition((*loot)->armor->sprite_data->sprite, *pos);
        sfSprite_setScale((*loot)->armor->sprite_data->sprite, *scale);
    } else {
        (*loot)->armor_or_weapon = 3;
    }
}

void add_pant(inventory_t *inventory, loot_t *loot, player_t *player)
{
    armor_t *temp = NULL;
    sfVector2f pos =
    sfSprite_getPosition(loot->armor->sprite_data->sprite);
    sfVector2f scale =
    sfSprite_getScale(loot->armor->sprite_data->sprite);

    if (inventory->pant != NULL) {
        temp = malloc(sizeof(armor_t));
        temp = inventory->pant;
    }
    inventory->pant = loot->armor;
    sfSprite_setPosition(inventory->pant->sprite_data->sprite,
    (sfVector2f){658, 245});
    sfSprite_setScale(inventory->pant->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    add_pant_pos(&loot, &pos, temp, &scale);
    if (temp == NULL)
        player->stat->armor += 1;
}

void add_boots_pos(loot_t **loot, sfVector2f *pos, armor_t *temp,
sfVector2f *scale)
{
    if (temp != NULL) {
        (*loot)->armor = temp;
        (*loot)->armor_or_weapon = 0;
        pos->x += 50;
        (*loot)->position.x += 50;
        sfSprite_setPosition((*loot)->armor->sprite_data->sprite, *pos);
        sfSprite_setScale((*loot)->armor->sprite_data->sprite, *scale);
    } else {
        (*loot)->armor_or_weapon = 3;
    }
}

void add_boots(inventory_t *inventory, loot_t *loot, player_t *player)
{
    armor_t *temp = NULL;
    sfVector2f pos =
    sfSprite_getPosition(loot->armor->sprite_data->sprite);
    sfVector2f scale =
    sfSprite_getScale(loot->armor->sprite_data->sprite);

    if (inventory->boots != NULL) {
        temp = malloc(sizeof(armor_t));
        temp = inventory->boots;
    }
    inventory->boots = loot->armor;
    sfSprite_setPosition(inventory->boots->sprite_data->sprite,
    (sfVector2f){658, 530});
    sfSprite_setScale(inventory->boots->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    add_boots_pos(&loot, &pos, temp, &scale);
    if (temp == NULL)
        player->stat->armor += 1;
}
