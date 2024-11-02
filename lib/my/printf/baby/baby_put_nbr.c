/*
** EPITECH PROJECT, 2024
** baby_put_nbr
** File description:
** display a int
*/
#include "my.h"

int baby_put_nbr(int nb, flags_t *flags, int i)
{
    if (nb < 0) {
        flags->prefix_buff.str = "-";
        flags->prefix_buff.count = 1;
        nb *= -1;
    }
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
