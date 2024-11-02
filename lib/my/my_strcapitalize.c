/*
** EPITECH PROJECT, 2024
** B-CPE-100-REN-1-1-cpoolday06-savinien.petitjean
** File description:
** Task 1
*/

#include "lib.h"

void my_strcapitalize2(char *p, char *str)
{
    if (!isalnum(*p) && p - str <= my_strlen(str))
        if (islower(*(p + 1)))
            *(p + 1) -= 32;
}

char *my_strcapitalize(char *str)
{
    char *p = str;

    my_strlowcase(str);
    if (islower(*p))
        *p -= 32;
    for (; *p; p++)
        my_strcapitalize2(p, str);
    return (str);
}
