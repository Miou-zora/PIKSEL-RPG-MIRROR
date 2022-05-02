/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** handle_menu_functions
*/

#include "struct_var.h"
#include "my.h"

// int game(void)
// {
//     my_rpg_player();
//     return (0);
// }

// int settings(scene_t *scene, settings_t *settings_struct)
// {
//     scene_t *new_scene = NULL;

//     if (free_scene(scene) == 84)
//         return (84);
//     if (initialize_settings(&(new_scene), scene) == 84)
//         return (84);
//     *scene = *new_scene;
//     if (scene == NULL)
//         return (84);
//     if (settings_struct->sound == false)
//         settings_struct->sound = true;
//     else
//         settings_struct->sound = false;
//     return (0);
// }

int quit(game_t *game)
{
    sfRenderWindow_close(game->window);
    return (0);
}

int detect_pos(sfVector2i position)
{
    sfVector2f **hitboxes = my_calloc(4, sizeof(sfVector2f *));

    hitboxes[0] = initialize_positions("365 295 1585 430", 2);
    hitboxes[1] = initialize_positions("365 535 1585 670", 2);
    hitboxes[2] = initialize_positions("365 775 1585 910", 2);
    hitboxes[3] = initialize_positions("1630 770 1800 990", 2);
    for (int i = 0; i < 4; i++) {
        if (position.x > hitboxes[i][0].x && position.x < hitboxes[i][1].x &&
        position.y > hitboxes[i][0].y && position.y < hitboxes[i][1].y)
            return(i);
    }
    return (-1);
}

int go_to_good_menu(sfVector2i position, game_t *game)
{
    int mouse_pos = detect_pos(position);
    // if (mouse_pos == 0) {
    //     return (game());
    // }
    // if (mouse_pos == 1) {
    //     if (settings(scene, settings_struct) == 84)
    //         return (84);
    // }
    if (mouse_pos == 2)
        quit(game);
    return (0);
}