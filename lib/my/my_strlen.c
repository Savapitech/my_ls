/*
** EPITECH PROJECT, 2024
** B-CPE-100-REN-1-1-cpoolday06-savinien.petitjean
** File description:
** Task 3
*/

#include "lib.h"

int my_strlen(char const *str)
{
    char const *p = str;

    for (; *p != '\0'; p++);
    return (p - str);
}
