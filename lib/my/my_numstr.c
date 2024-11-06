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
        ptr[1] = '\0';
        return ptr;
    }
    ptr += len;
    for (; nb > 0; nb /= 10) {
        ptr--;
        *ptr = (nb % 10) + '0';
    }
    ptr[len] = '\0';
    return ptr;
}
