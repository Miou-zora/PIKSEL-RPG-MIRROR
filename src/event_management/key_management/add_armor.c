/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** add_armor
*/

#include "struct_var.h"
#include "my.h"

void add_helmet_pos(loot_t **loot, sfVector2f *pos, armor_t *temp,
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

void add_helmet(inventory_t *inventory, loot_t *loot, player_t *player)
{
    armor_t *temp = NULL;
    sfVector2f pos =
    sfSprite_getPosition(loot->armor->sprite_data->sprite);
    sfVector2f scale =
    sfSprite_getScale(loot->armor->sprite_data->sprite);

    if (inventory->helmet != NULL) {
        temp = malloc(sizeof(armor_t));
        temp = inventory->helmet;
    }
    inventory->helmet = loot->armor;
    sfSprite_setPosition(inventory->helmet->sprite_data->sprite,
    (sfVector2f){355, 245});
    sfSprite_setScale(inventory->helmet->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    add_helmet_pos(&loot, &pos, temp, &scale);
    if (temp == NULL)
        player->stat->armor += 1;
}

void add_chestplate_pos(loot_t **loot, sfVector2f *pos, armor_t *temp,
sfVector2f *scale)
{
    if (temp != NULL) {
        (*loot)->armor = temp;
        (*loot)->armor_or_weapon = 0;
        pos->x += 50;
        (*loot)->position.x += 50;
        sfSprite_setPosition((*loot)->armor->sprite_data->sprite, *pos);
        sfSprite_setScale((*loot)->armor->sprite_data->sprite, *scale);
    } else
        (*loot)->armor_or_weapon = 3;
}

void add_chestplate(inventory_t *inventory, loot_t *loot, player_t *player)
{
    armor_t *temp = NULL;
    sfVector2f pos =
    sfSprite_getPosition(loot->armor->sprite_data->sprite);
    sfVector2f scale =
    sfSprite_getScale(loot->armor->sprite_data->sprite);

    if (inventory->chestplate != NULL) {
        temp = malloc(sizeof(armor_t));
        temp = inventory->chestplate;
    }
    inventory->chestplate = loot->armor;
    sfSprite_setPosition(inventory->chestplate->sprite_data->sprite,
    (sfVector2f){355, 530});
    sfSprite_setScale(inventory->chestplate->sprite_data->sprite,
    (sfVector2f){2.1, 2.1});
    add_chestplate_pos(&loot, &pos, temp, &scale);
    if (temp == NULL)
        player->stat->armor += 2;
}
