/*
** EPITECH PROJECT, 2022
** PIKSEL-RPG-MIRROR
** File description:
** put_str_error
*/

#include <unistd.h>
#include "my.h"

int put_str_error(char *str)
{
    if (str == NULL)
        return (0);
    if (write(2, str, my_strlen(str)) == -1) {
        return (84);
    } else {
        return (0);
    }
}