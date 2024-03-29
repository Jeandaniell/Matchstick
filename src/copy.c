/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return (dest);
}

char **d_strcpy(char **dest, char **src)
{
    int i = 0;

    for (i = 0; src[i]; i++)
        my_strcpy(dest[i], src[i]);
    dest[i] = NULL;

    return (dest);
}
