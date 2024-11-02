/*
** EPITECH PROJECT, 2024
** CPoolDay07
** File description:
** ./my_isneg.c
*/

#include "lib.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
