/*
** EPITECH PROJECT, 2024
** CPoolDay08
** File description:
** ./my_strdup.c
*/

#include "lib.h"

char *my_strdup(char const *src)
{
    char *dest;
    int len = my_strlen(src);

    dest = malloc(sizeof(char) * (len + 1));
    return my_strcpy(dest, src);
}
