/*
** EPITECH PROJECT, 2024
** CPoolDay07
** File description:
** ./my_putstr.c
*/

#include "lib.h"

int my_puterr(char const *str)
{
    return write(STDERR_FILENO, str, my_strlen(str));
}
