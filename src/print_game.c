/*
** EPITECH PROJECT, 2021
** print_game
** File description:
** print_game
*/

#include "../include/my.h"

void fill_up_tab(char **board, int colonnes, int middle, int lines)
{
    int i = 0, j = 0, n = 0;
    int k = middle + 1, f = middle - 1;
    colonnes = (lines * 2) - 2, middle = (colonnes / 2) - 1;
    for (i = 0; board[i] != NULL; i++) {
        board[i][middle] = '|';
        if (i > 1) {
            while (n < i) {
                board[i][f] = '|';
                board[i][k] = '|';
                n++, f--, k++;
            }
        }
        for (j = 0; board[i][j] != '\n'; j++) {
            if (i == 0 || i == lines-1 || j == 0 || j == colonnes-2)
                board[i][j] = '*';
            else if (board[i][j] != '|')
                board[i][j] = ' ';
        }
        f = middle, k = middle, n = 0;
    }
}

char **print_game_board(int lines)
{
    int i = 0;
    char **board = malloc(sizeof(char *) * lines);
    int colonnes = (lines * 2) - 2, middle = (colonnes / 2) - 1;

    for (i = 0; i < lines; i++)
        board[i] = malloc(sizeof(char) * colonnes);
    board[lines] = NULL;
    for (i = 0; board[i] != NULL; i++) {
        board[i][colonnes-1] = '\n';
        board[i][colonnes] = '\0';
    }
    fill_up_tab(board, colonnes, middle, lines);

    return (board);
    free(board);
}

char **print_upd_board_game(char **tab, int line, int nb_matches)
{
    int i = 0, j = 0, p = my_strlen(tab[i])-1, x = 0;

    for (i = 0; tab[i] != NULL; i++) {
        for (j = p - 1, x = 0; j != -1; j--) {
            if (i == line && tab[line][j] == '|' && x < nb_matches) {
                tab[line][j] = ' ';
                x++;
            }
        }
    }
    return (tab);
}

void browse_d_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++)
            write(1, &tab[i][j], 1);
}

int read_print_board_game(char **av)
{
    char **tab = print_game_board(my_getnbr(av[1]) + 2), **stock_tab;
    int *stock;
    while (1) {
        browse_d_tab(tab);
        my_putchar('\n');
        my_putstr("Your turn: \n");
        stock = user(tab, av);
        if (stock[0] == -1 && stock[1] == -1) return (0);
        stock_tab = print_upd_board_game(tab, stock[0], stock[1]);
        user_interface(stock[0], stock[1]);
        browse_d_tab(stock_tab);
        if (count_sticks(tab) == 0) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        if (count_sticks(sticks_ia(stock_tab, av)) == 0) {
            browse_d_tab(tab);
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
}
