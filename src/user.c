/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"

int invalid_character(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\n'; i++)
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (84);
        }
}

int case_error(char **tab, int n1, int nb, char **av, char *str)
{
    if (invalid_character(str) == 84)
        return (84);
    else
        if (error(nb, av) == 84 || ror_m(nb, av) == 84
            || error_line_matches(tab, n1, nb, av) == 84)
            return (84);
        else
            return (1);
}

int *user(char **tab, char **av)
{
    char *line, *matches;
    size_t nb1 = 0, nb2 = 0;
    int n1 = 0, n2 = 0;
    int *number = malloc(sizeof(int) * 2);

    my_putstr("Line: ");
    if (getline(&line, &nb1, stdin) == -1) {
        number[0] = -1;
        number[1] = -1;
        return (number);
    }
    n1 = my_getnbr(line);
    if (error_line(n1, av, line) == 1) {
        my_putstr("Matches: ");
        if (getline(&matches, &nb2, stdin) == -1) {
            number[0] = -1;
            number[1] = -1;
            return (number);
        }
        n2 = my_getnbr(matches);
        if (case_error(tab, n1, n2, av, matches) == 1) {
            number[0] = n1;
            number[1] = n2;
            return (number);
            free (number);
        } else
            user(tab, av);
    } else
        user(tab, av);
}
