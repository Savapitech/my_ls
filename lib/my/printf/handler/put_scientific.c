/*
** EPITECH PROJECT, 2024
** put_hex
** File description:
** display an int in hexadecimal format
*/

#include <math.h>

#include "my.h"

static
void inf_or_nan(double nbr, flags_t *flags)
{
    if (nbr < 0){
        flags->prefix_buff.str = "-";
        flags->prefix_buff.count = 1;
    }
    if (isinf(nbr))
        baby_put_inf(flags);
    if (isnan(nbr))
        baby_put_nan(flags);
}

static
void print_scientific(char sign, flags_t *flags, int e, double nb)
{
    char e_char = isupper(flags->spec) ? 'E' : 'e';

    baby_put_float(nb, flags);
    flags->spec_buff.str[flags->spec_buff.count] = e_char;
    flags->spec_buff.str[flags->spec_buff.count + 1] = sign;
    flags->spec_buff.count += 2;
    if (e < 10) {
        flags->spec_buff.str[flags->spec_buff.count] = '0';
        flags->spec_buff.count++;
    }
    baby_put_nbr(e, flags, flags->spec_buff.count);
}

void printf_put_scientific(flags_t *flags)
{
    double nb = va_arg(flags->args, double);
    int e = 0;
    char sign = '+';

    if (isnan(nb) || isinf(nb))
        return inf_or_nan(nb, flags);
    if (nb < 0) {
        flags->prefix_buff.str = "-";
        flags->prefix_buff.count = 1;
    }
    nb = ABS(nb);
    if (nb >= 1 && nb != 0)
        for (; nb >= 10; nb /= 10)
            e++;
    if (nb < 1 && nb != 0) {
        sign = '-';
        for (; nb < 1 && nb <= 10; nb *= 10)
            e++;
    }
    print_scientific(sign, flags, e, nb);
}
