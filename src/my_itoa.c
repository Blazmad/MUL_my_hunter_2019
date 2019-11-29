/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_itoa.c
*/

#include "my.h"

char *my_itoa(int number)
{
    char *res = malloc(sizeof(char) * 20);
    int i = 0;
    int j = 1;
    int k = number;

    while (j <= number)
        j *= 10;
    j /= 10;
    for (; j != 0; i++, j /= 10, number = k) {
        number /= j;
        res[i] = number + 48;
        k -= (j * number);
        number *= j;
    }
    res[i] = '\0';
    return (res);
}