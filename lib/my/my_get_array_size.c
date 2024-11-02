/*
** EPITECH PROJECT, 2024
** B-CPE-100-REN-1-1-cpoolday10-savinien.petitjean
** File description:
** ./do-op/my_do-op.c
*/

#include "lib.h"

int my_get_array_size(char **tab)
{
    int i = 0;

    for (; tab[i] != 0; i++);
    return i;
}
