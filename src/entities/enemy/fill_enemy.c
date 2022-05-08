/*
** EPITECH PROJECT, 2022
** PIKSEL-ALEX
** File description:
** fill_enemy
*/

#include "struct_var.h"
#include "my.h"

enum types_enemy get_type_enemy(char *type)
{
    char *str_types_enemy[] = {"mob", "mini_boss", "boss"};

    for (int i = 0; i < 3; i++) {
        if (my_strcmp(type, str_types_enemy[i]) == 0)
            return (i + 1);
    }
    return (NOT_SET);
}

static stat_t load_stat(char **data)
{
    stat_t stat;

    stat.health = my_getnbr(data[3]);
    stat.actual_life = stat.health;
    stat.armor = my_getnbr(data[4]);
    stat.power = my_getnbr(data[5]);
    stat.speed = my_getnbr(data[6]);
    return (stat);
}

static bool check_error(enemy_t *enemy)
{
    bool error = false;

    error |= (enemy->stat.health == 0);
    error |= (enemy->name == NULL);
    error |= (enemy->type_enemy == NOT_SET);
    error |= (enemy->animator_standing == NULL);
    return (error);
}

enemy_t *fill_enemy(enemy_t *enemy, char **data)
{
    if (data == NULL || get_len_array(data) != 8 || enemy == NULL) {
        return (NULL);
    } else {
        enemy->type_enemy = get_type_enemy(data[0]);
        enemy->name = my_strdup(data[1]);
        enemy->id = my_getnbr(data[2]);
        enemy->stat = load_stat(data);
        enemy->animator_standing = load_animator(data[7]);
        if (check_error(enemy)) {
            return (NULL);
        }
        enemy->attack_clock = create_clock_data();
        set_framerate_clock_data(enemy->attack_clock, 0.1);
    }
    return (enemy);
}
