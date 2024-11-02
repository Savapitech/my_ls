/*
** EPITECH PROJECT, 2024
** revstr
** File description:
** reverse an str given as parameter
*/

#include "my.h"

char *baby_revstr(char *str)
{
    int len = baby_strlen(str);
    char copy;

    for (int i = 0; i < len / 2; i++) {
        copy = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = copy;
    }
    return (str);
}
