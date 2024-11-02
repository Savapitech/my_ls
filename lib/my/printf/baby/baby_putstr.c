/*
** EPITECH PROJECT, 2024
** putstr
** File description:
** put an str
*/

#include "my.h"

int baby_putstr(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        count += baby_putchar(str[i]);
    return (count);
}
