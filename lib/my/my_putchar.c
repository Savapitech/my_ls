/*
** EPITECH PROJECT, 2024
** CPoolDay07
** File description:
** ./my_putchar.c
*/

#include "lib.h"



#include <unistd.h>

int my_putchar(char a)
{
    return (write(1, &a, 1) - 1);
}
