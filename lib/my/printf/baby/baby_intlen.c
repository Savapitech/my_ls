/*
** EPITECH PROJECT, 2024
** intlen
** File description:
** count the decimal of an int given as parameter
*/
#include <stdint.h>
#include <stdlib.h>

size_t baby_intlen(size_t nb, int base)
{
    int i = 0;

    for (; nb != 0; i++)
        nb /= base;
    return i;
}
