/*
** EPITECH PROJECT, 2024
** CPoolDay07
** File description:
** ./my_putstr.c
*/

#include "lib.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
