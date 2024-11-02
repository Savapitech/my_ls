/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "my.h"

int baby_stridx(char const *str, char c)
{
    int i = 0;

    if (str == NULL)
        return -1;
    for (; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return -1;
}
