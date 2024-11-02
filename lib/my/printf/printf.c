/*
** EPITECH PROJECT, 2024
** point_exa
** File description:
** display the adress in hexa
*/

#include "my.h"

int my_printf(char *fmt, ...)
{
    va_list args;
    int result = 0;

    if (!fmt)
        return EXIT_ERROR;
    va_start(args, fmt);
    result = printf_parser(fmt, args);
    va_end(args);
    return result;
}
