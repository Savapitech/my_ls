/*
** EPITECH PROJECT, 2024
** point_exa
** File description:
** display the adress in hexa
*/

#include "my.h"

void printf_putchar(flags_t *flags)
{
    int c = va_arg(flags->args, int);

    flags->spec_buff.str[0] = c;
    flags->spec_buff.count = 1;
}
