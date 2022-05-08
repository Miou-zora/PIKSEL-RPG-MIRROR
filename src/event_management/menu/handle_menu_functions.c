/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_menu_functions
*/

#include "struct_var.h"
#include "my.h"

int launch_game(game_t *game)
{
    game->background->scene_background = CINEMATIC;
    return (0);
}

int settings(game_t *game)
{
    sprite_data_t *settings_background = NULL;
    settings_background = load_sprite_data("assets/menu/settings.png");
    sfSprite_setScale(settings_background->sprite, (sfVector2f){8, 8});
    sfSprite_setPosition(settings_background->sprite, (sfVector2f){0, 0});
    game->background->menu->sprite = settings_background;
    if (initialize_settings_rectangles(game->background->menu, game) == 84)
        return (84);
    game->background->scene_background = SETTINGS;
    return (0);
}

int quit(game_t *game)
{
    sfRenderWindow_close(game->window);
    return (0);
}

int detect_pos(sfVector2i position)
{
    sfVector2f **hitboxes = my_calloc(4, sizeof(sfVector2f *));
    my_printf("hit bosxe\n");
    hitboxes[0] = initialize_positions("365 295 1585 430", 2);
    hitboxes[1] = initialize_positions("365 535 1585 670", 2);
    hitboxes[2] = initialize_positions("365 775 1585 910", 2);
    hitboxes[3] = initialize_positions("1630 770 1800 990", 2);
    for (int i = 0; i < 4; i++) {
        if (position.x > hitboxes[i][0].x && position.x < hitboxes[i][1].x &&
        position.y > hitboxes[i][0].y && position.y < hitboxes[i][1].y)
            return (i);
    }
    freen(&(*hitboxes));
    return (-1);
}

int go_to_good_menu(sfVector2i position, game_t *game)
{
    int mouse_pos = detect_pos(position);

    if (mouse_pos == 0) {
        reset_clock_data(game->cinematic->clock_move_player);
        reset_clock_data(game->cinematic->clock_move_enemy);
        return (launch_game(game));
    }
    if (mouse_pos == 1) {
        if (settings(game) == 84)
            return (84);
    }
    if (mouse_pos == 2)
        quit(game);
    if (mouse_pos == 3)
        how_to_play(game);
    return (0);
}