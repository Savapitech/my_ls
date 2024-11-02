/*
** EPITECH PROJECT, 2024
** point_exa
** File description:
** display the adress in hexa
*/

#include <limits.h>
#include <stdio.h>

#include "my.h"

static
const size_t NULL_LEN = sizeof "(null)" - 1;

void printf_putstr(flags_t *flags)
{
    int count = 0;
    char *str = va_arg(flags->args, char *);

    if (str == NULL && (size_t)flags->precision < NULL_LEN) {
        flags->spec_buff.str = "";
        return;
    }
    if (str == NULL) {
        flags->spec_buff.str = "(null)";
        flags->spec_buff.count = NULL_LEN;
        return;
    }
    if (flags->precision == -1)
        flags->precision = INT_MAX;
    for (; str[count] && count < flags->precision; count++);
    flags->spec_buff.str = str;
    flags->spec_buff.count = count;
    if (flags->precision == INT_MAX)
        flags->precision = -1;
}
