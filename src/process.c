/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** Matchstick
*/

#include "../include/my.h"

void user_interface(int n1, int n2)
{
    my_putstr("Player removed ");
    my_putnbr(n2);
    my_putstr(" match(es) from line ");
    my_putnbr(n1);
    my_putchar('\n');
}

int count_sticks(char **tab)
{
    int i = 0, j = 0, m = 0;

    for (i = 0; tab[i]; i++)
        for (j = 0; tab[i][j] != '\0'; j++)
            if (tab[i][j] == '|') m++;

    return (m);
}

int line_sticks(int line, char **tab)
{
    int i = 0, j = 0, t = 0;

    for (i = 0; tab[i]; i++) {
        for (j = 0; tab[i][j] != '\n'; j++)
            if (i == line && tab[i][j] == '|')
                t++;
    }
    return (t);
}

int my_str_isnum(char const *str)
{
    int i = 0, n = 0;

    for (i = 0; str[i]; i++)
        if (str[i] >= '0' && str[i] <= '9') n++;
    if (n == my_strlen(str))
        return (1);
    else
        return (0);
}
