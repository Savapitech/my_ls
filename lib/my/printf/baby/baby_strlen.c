/*
** EPITECH PROJECT, 2024
** strlen
** File description:
** len
*/

int baby_strlen(char *str)
{
    char *p = str;

    for (; *p != '\0'; p++);
    return (p - str);
}
