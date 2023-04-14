/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** Matchstick
*/

#include "../include/my.h"

int gen_number(int limit, int number_sticks)
{
    int a = random(), b = 0;
    srandom(time(NULL));

    if (limit <= number_sticks)
        b = (a % limit) + 1;
    else
        b = (a % number_sticks) + 1;

    return (b);
}