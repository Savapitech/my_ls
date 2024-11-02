/*
** EPITECH PROJECT, 2024
** B-CPE-100-REN-1-1-cpoolday06-savinien.petitjean
** File description:
** Task 3
*/

#include "lib.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char copy;

    for (int i = 0; i < len / 2; i++) {
        copy = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = copy;
    }
    return (str);
}
