/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** create_framebuffer
*/

#include "struct_var.h"
#include "my.h"

framebuffer_t *create_framebuffer(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = my_calloc(1, sizeof(*framebuffer));
    my_printf("create frambuf\n");
    if (framebuffer) {
        framebuffer->width = width;
        framebuffer->height = height;
        framebuffer->pixels = my_calloc(width * height + 1, sizeof(int));
    }
    return (framebuffer);
}

void destroy_framebuffer(framebuffer_t **framebuffer)
{
    freen(&((*framebuffer)->pixels));
    freen(&framebuffer);
}
