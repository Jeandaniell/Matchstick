/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** Matchstick
*/

#include "../include/my.h"

void ia_interface(int n3, int n4)
{
    my_putchar('\n');
    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    my_putnbr(n3);
    my_putstr(" match(es) from line ");
    my_putnbr(n4);
    my_putchar('\n');
}

char **sticks_ia(char **tab, char **av)
{
    int i = 0, j = 0;
    int n = 1;
    int n1 = 1;

    while (line_sticks(n, tab) == 0)
        n++;
    if (line_sticks(n, tab) != 0) {
        n1 = gen_number(my_getnbr(av[2]), line_sticks(n, tab));
        ia_interface(n1, n);
        return (print_upd_board_game(tab, n, n1));
    }
}

int msg_ia(char **tab)
{
    if (count_sticks(tab) == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
}
