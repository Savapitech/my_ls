/*
** EPITECH PROJECT, 2024
** put_oct
** File description:
** display an int given as parameter in octal format
*/

#include <stdio.h>

#include "my.h"

int baby_put_oct(int nb, flags_t *flags)
{
    size_t result = (size_t)nb;
    char str[64];
    int i = 0;

    for (; nb != 0; i++) {
        result = nb % 8;
        str[i] = (result + '0');
        nb = nb / 8;
    }
    str[i] = '\0';
    baby_revstr(str);
    baby_strcpy(flags->spec_buff.str, str);
    flags->spec_buff.count = i;
    return 0;
}

void printf_put_oct(flags_t *flags)
{
    int nb = va_arg(flags->args, int);

    if (flags->precision == 0 && nb == 0)
        return;
    if (nb == 0) {
        flags->spec_buff.str = "0";
        flags->spec_buff.count = 1;
        return;
    }
    if (flags->precision > 0) {
        if (flags->flags & FLAGS_PAD_RIGHT)
            flags->flags &= ~FLAGS_PAD_RIGHT;
        flags->flags |= FLAGS_PAD_ZERO;
        flags->width = flags->precision;
    }
    baby_put_oct(nb, flags);
}
