/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int my_putnbr(int nb)
{
    int x;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48);
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}

int  my_getnbr(char const *str)
{
    int i = 0, j = 0, nb = 1;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            nb = (-1) * nb;
        if (str[i] == '+')
            nb = nb;
        if (str[i] >= 48 && str[i] <= 57) {
            j = (j * 10) + (str[i] - 48);
            if (str[i+1] < 48 || str[i+1] > 57)
                if (str[i+1] != 43 && str[i+1] != 45)
                break;
        }
    }
    return (nb * j);
}
