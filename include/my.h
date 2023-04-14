/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** my.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>

typedef struct sticks
{
    char **board;
    int n1;
    int n2;
    size_t nb1;
    size_t nb2;
    int *stock_result;
    char **tab;
    char *line;
    char *matches;
    char *value_line;
    char *balue_matches;
    char **stock_tab;
    int *stock;
    int i;
    int j;
}sticks;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_putnbr(int nb);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char **d_strcpy(char **dest, char **src);
void fill_up_tab(char **board, int colonnes, int middle, int lines);
char **print_game_board(int lines);
char **print_upd_board_game(char **tab, int line, int nb_matches);
int read_print_board_game(char **av);
void user_interface(int n1, int n2);
void ia_interface(int n3, int n4);
int count_sticks(char **tab);
int line_sticks(int line, char **tab);
char **sticks_ia(char **tab, char **av);
int gen_number(int limit, int number_sticks);
int *user(char **tab, char **av);
int msg_ia(char **tab);
void browse_d_tab(char **tab);
int error_line(int n1, char **av, char *str);
int ror_m(int n2, char **av);
int error(int n2, char **av);
int error_line_matches(char **tab, int n1, int n2, char **av);
int case_error(char **tab, int n1, int nb, char **av, char *str);
int invalid_character(char *str);
int my_str_isnum(char const *str);