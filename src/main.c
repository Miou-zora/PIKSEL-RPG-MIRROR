/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** rpg main
*/

#include "my.h"
#include "rpg.h"

int my_rpg(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (initialize_var(game) == 84)
        return (84);
    while (sfRenderWindow_isOpen(game->window)) {
        display(game);
        set_mouse_cursor(game);
        sfRenderWindow_display(game->window);
        //while (sfRenderWindow_pollEvent(game->window, game->event))
            //analyse_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
    }
    free_all(game);
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    if (my_rpg() == 84)
        return (84);
}