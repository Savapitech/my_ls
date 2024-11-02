/*
** EPITECH PROJECT, 2023
** CPoolDay07
** File description:
** ./my_strcat.c
*/

#include "lib.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i;
    int count;
    char *res;

    i = 0;
    count = 0;
    res = malloc(sizeof(*res) * (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i]) {
        res[i] = dest[i];
        i++;
    }
    while (src[count]) {
        res[i + count] = src[count];
        count++;
    }
    res[i + count] = '\0';
    return (res);
}
