/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-my_rpg_kentin_paille
** File description:
** init sprite and data in rpg
*/

#include "my.h"
#include "struct_var.h"


bool init_sound(sound_music_t *sound_music)
{
    sound_music = malloc(sizeof(sound_music_t));

    sound_music->music = sfMusic_createFromFile("assets/sound_music/music.ogg");
    sound_music->sound_buff = sfSoundBuffer_createFromFile("assets/sound_music/sound_damage.ogg");
    if (sound_music->sound_buff == NULL)
        return (true);
    sound_music->sound = sfSound_create();
    // sfSound_setVolume(sound_music->sound, 10.f);
    sfSound_setBuffer(sound_music->sound, sound_music->sound_buff);
    sfMusic_play(sound_music->music);
    // sfSound_play(sound_music->sound);
    return (false);
}
