/*
** EPITECH PROJECT, 2024
** CPoolDay07
** File description:
** ./my_swap.c
*/

#include "lib.h"



void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
