/*
** EPITECH PROJECT, 2024
** CPoolDay08
** File description:
** ./lin/my/my_show_word_array.c
*/

#include "lib.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
