/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** display the number given as parameter
*/

#include <stdio.h>

#include "my.h"

void printf_put_nbr(flags_t *flags)
{
    int nb = va_arg(flags->args, int);

    if (flags->flags & FLAGS_SET_SPACE) {
        flags->prefix_buff.str = " ";
        flags->prefix_buff.count = 1;
    }
    if (flags->flags & FLAGS_PUT_SIGN) {
        flags->prefix_buff.str = "+";
        flags->prefix_buff.count = 1;
    }
    if (flags->precision == 0 || (nb == 0 && flags->precision == -1))
        return;
    if (flags->precision > 0) {
        if (flags->flags & FLAGS_PAD_RIGHT)
            flags->flags &= ~FLAGS_PAD_RIGHT;
        flags->flags |= FLAGS_PAD_ZERO;
        flags->width = flags->precision;
    }
    baby_put_nbr(nb, flags, 0);
}
