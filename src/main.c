/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "struct_var.h"

int my_rpg(void)
{
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    armor_t **all_armors = load_all_armors("scripts/armor");

    if (all_armors == NULL)
        return (84);
    for (int i = 0; all_armors[i]; i++) {
        print_armor(all_armors[i]);
    }
    destroy_all_armors(&all_armors);
    if (my_rpg() == 84)
        return (84);
}