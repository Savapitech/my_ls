/*
** EPITECH PROJECT, 2024
** put_hex
** File description:
** display an int in hexadecimal format
*/

#include <math.h>

#include "my.h"

static
int choose_prec_neg(flags_t *flags, int nbr, int copy)
{
    if (flags->precision == -1)
        flags->precision = 6;
    if (nbr < 0 && copy == 0) {
        flags->prefix_buff.str = "-";
        flags->prefix_buff.count = 1;
    }
    return flags->precision;
}

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
void put_sign(flags_t *flags, double nbr, int copy)
{
    if (flags->flags & FLAGS_SET_SPACE) {
        flags->prefix_buff.str = " ";
        flags->prefix_buff.count = 1;
    }
    if (flags->flags & FLAGS_PUT_SIGN) {
        flags->prefix_buff.str = "+";
        flags->prefix_buff.count = 1;
    }
    if (nbr < 0 && copy == 0) {
        flags->prefix_buff.str = "-";
        flags->prefix_buff.count = 1;
    }
}

static
int put_point(flags_t *flags, int i)
{
    if (flags->precision > 0 || flags->precision == -1 ||
        flags->flags & FLAGS_ALT_FORM) {
        flags->spec_buff.str[i] = '.';
        return 1;
    }
    return 0;
}

static
void round_float(flags_t *flags, int i)
{
    int a = i - 1;

    for (; isdigit(flags->spec_buff.str[a]) &&
        flags->spec_buff.str[a] >= '5'; a--) {
        flags->spec_buff.str[a] = '0';
    }
    if (isdigit(flags->spec_buff.str[a]))
        flags->spec_buff.str[a]++;
}

void baby_put_float(double nbr, flags_t *flags)
{
    int copy = (int)nbr;
    int precision = choose_prec_neg(flags, nbr, copy);
    int i = 0;

    if (isnan(nbr) || isinf(nbr))
        return inf_or_nan(nbr, flags);
    put_sign(flags, nbr, copy);
    i = baby_put_nbr(copy, flags, i);
    i += put_point(flags, i);
    nbr -= copy;
    for (int j = 0; j < precision + 1; j++) {
        nbr = (nbr - (int)nbr) * 10;
        i = baby_put_nbr((int)(nbr < 0 ? - nbr : nbr), flags, i);
    }
    round_float(flags, i);
    flags->spec_buff.count = i - 1;
}

void printf_put_float(flags_t *flags)
{
    baby_put_float(va_arg(flags->args, double), flags);
};
