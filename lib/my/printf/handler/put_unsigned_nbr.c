/*
** EPITECH PROJECT, 2024
** put_unsigned_nbr
** File description:
** display an unsigned number given as parameter
*/

#include "my.h"

static
int baby_put_unsigned_nbr(unsigned int nb, flags_t *flags, int i)
{
    if (nb < 10)
        flags->spec_buff.str[i] = nb + '0';
    else {
        i = baby_put_nbr(nb / 10, flags, i);
        flags->spec_buff.str[i] = nb % 10 + '0';
    }
    i++;
    flags->spec_buff.count = i;
    return i;
}

void printf_put_unsigned_nbr(flags_t *flags)
{
    if (flags->precision > 0) {
        if (flags->flags & FLAGS_PAD_RIGHT)
            flags->flags &= ~FLAGS_PAD_RIGHT;
        flags->flags |= FLAGS_PAD_ZERO;
        flags->width = flags->precision;
    }
    baby_put_unsigned_nbr(va_arg(flags->args, int), flags, 0);
}
