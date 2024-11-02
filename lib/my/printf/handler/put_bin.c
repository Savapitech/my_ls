/*
** EPITECH PROJECT, 2024
** put_bin
** File description:
** display a int in his binary format
*/
#include "my.h"

void printf_put_bin(flags_t *flags)
{
    int nb = va_arg(flags->args, int);
    int result = nb;
    int len = baby_intlen(nb, 2);
    char str[baby_intlen(nb, 2)];

    if (nb == 0){
        flags->spec_buff.str = "0";
        flags->spec_buff.count = 1;
        return;
    }
    for (int i = 0; nb != 0; i++) {
        result = nb % 2;
        str[i] = (result + 48);
        nb /= 2;
    }
    str[len] = '\0';
    baby_revstr(str);
    flags->spec_buff.count = len;
    baby_strcpy(flags->spec_buff.str, str);
}
