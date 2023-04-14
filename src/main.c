/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac == 3 && my_str_isnum(av[1]) == 1 && my_str_isnum(av[2]) == 1)
        return (read_print_board_game(av));
    else
        return (84);
}
