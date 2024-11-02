/*
** EPITECH PROJECT, 2024
** CPoolDay07
** File description:
** ./my_strncat.c
*/

#include "lib.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i] != '\0' && i < nb) {
        dest[i + len] = src[i];
        i++;
    }
    dest[i + len] = '\0';
    return dest;
}
