/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** init sprite and data in rpg
*/

#include "my.h"
#include "struct_var.h"

bool create_sound_from_file(sound_music_t **sound_music)
{
    (*sound_music)->music = sfMusic_createFromFile
    ("assets/sound_music/music.ogg");
    (*sound_music)->sound_buff_damage = sfSoundBuffer_createFromFile
    ("assets/sound_music/sound_damage.ogg");
    if ((*sound_music)->sound_buff_damage == NULL)
        return (true);
    (*sound_music)->sound_buff_teleport = sfSoundBuffer_createFromFile
    ("assets/sound_music/teleport.ogg");
    if ((*sound_music)->sound_buff_teleport == NULL)
        return (true);
    (*sound_music)->sound_buff_terry = sfSoundBuffer_createFromFile
    ("assets/sound_music/terry.ogg");
    if ((*sound_music)->sound_buff_terry == NULL)
        return (true);
    return (false);
}

bool init_sound(sound_music_t **sound_music)
{
    (*sound_music) = malloc(sizeof(sound_music_t));
     my_printf("malloc sound\n");
    if (create_sound_from_file(sound_music) == true)
        return (true);
    (*sound_music)->damage = sfSound_create();
    (*sound_music)->teleport = sfSound_create();
    (*sound_music)->terry = sfSound_create();
    sfSound_setBuffer((*sound_music)->damage,
    (*sound_music)->sound_buff_damage);
    sfSound_setBuffer((*sound_music)->teleport,
    (*sound_music)->sound_buff_teleport);
    sfSound_setBuffer((*sound_music)->terry,
    (*sound_music)->sound_buff_terry);
    sfMusic_setLoop((*sound_music)->music, sfTrue);
    sfMusic_play((*sound_music)->music);
    return (false);
}
