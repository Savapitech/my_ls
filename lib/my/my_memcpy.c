/*
** EPITECH PROJECT, 2024
** CPoolDay08
** File description:
** ./my_realloc.c
*/

#include "lib.h"
#include <stdint.h>

void *my_memcpy(uint8_t *dest, uint8_t const *src, size_t n)
{
    for (size_t i = 0; i < n; i++)
        dest[i] = src[i];
    return dest;
}
