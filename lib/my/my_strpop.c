/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** lib/mu/my_strpop.c
*/

#include <stdlib.h>
#include "lib.h"

char *my_strpop(char *str, int size)
{
    int l = my_strlen(str);
    char *strr = malloc(l - size);

    for (int i = 0; i < l - size; i++) {
        strr[i] = str[i];
    }
    strr[l - size] = '\0';
    return strr;
}
