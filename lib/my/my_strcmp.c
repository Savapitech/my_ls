/*
** EPITECH PROJECT, 2024
** B-CPE-100-REN-1-1-cpoolday06-savinien.petitjean
** File description:
** Task 1
*/

#include "lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0'; i++);
    return s1[i] - s2[i];
}
