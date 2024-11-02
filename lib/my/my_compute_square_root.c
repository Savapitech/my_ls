/*
** EPITECH PROJECT, 2024
** CPoolDay07
** File description:
** ./my_compute_square_root.c
*/

#include "lib.h"



int my_compute_square_root(int nb)
{
    if (nb <= 0)
        return 0;
    for (int i = 1; i <= nb / 2 + 1; i++) {
        if (i * i == nb)
            return (i);
    }
    return (0);
}
