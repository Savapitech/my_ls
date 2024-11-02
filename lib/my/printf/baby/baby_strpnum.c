/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include <limits.h>

#include "my.h"

int baby_strpnum(char **ptr)
{
    char *s = *ptr;
    int n = 0;

    if (!isdigit(*s))
        return -1;
    for (; isdigit(*s); s++) {
        if ((INT_MAX / 10 - CHAR_TO_DIGIT(*s)) < n)
            return (-2);
        n = n * 10 + CHAR_TO_DIGIT(*s);
    }
    *ptr = s;
    return n;
}
