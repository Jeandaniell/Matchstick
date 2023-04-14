/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"

int error_line(int n1, char **av, char *str)
{
    if (invalid_character(str) == 84)
        return (84);
    else
        if (n1 <= 0 || n1 > my_getnbr(av[1])) {
            my_putstr("Error: this line is out of range\n");
            return (84);
        } else
            return (1);
}

int error(int n2, char **av)
{
    if (n2 <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (84);
    } else
        return (1);
}

int ror_m(int n2, char **av)
{
    if (n2 > my_getnbr(av[2])) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(my_getnbr(av[2]));
        my_putstr(" matches per turn\n");
        return (84);
    } else
        return (1);
}

int error_line_matches(char **tab, int n1, int n2, char **av)
{
    int i = 0, j = 0;

    if (line_sticks(n1, tab) < n2 && ror_m(n2, av) == 1) {
        my_putstr("Error: not enough matches on this line\n");
        return (84);
    } else
        return (1);
}
