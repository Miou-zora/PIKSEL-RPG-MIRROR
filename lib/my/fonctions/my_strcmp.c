/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** The strcmp() function compares the two strings s1 and s2.
*/

int my_strcmp(char const *s1 , char const *s2)
{
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}
