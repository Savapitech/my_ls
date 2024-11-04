/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "lib.h"

char *my_numstr(char *ptr, int nb)
{
    int len = baby_intlen(nb, 10);

    if (nb == 0) {
        *ptr = '0';
        return ptr;
    }
    ptr += len - 1;
    for (; nb > 0; nb /= 10) {
        *ptr = (nb % 10) + '0';
        ptr--;
    }
    return ptr;
}
