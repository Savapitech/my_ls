/*
** EPITECH PROJECT, 2024
** SH_PUTNBR
** File description:
** Outputs a given int.
*/

#include "lib.h"

static void my_put_positive(int nb, int *count)
{
    if (nb > 9)
        my_put_positive(nb / 10, count);
    my_putchar(nb % 10 + '0');
    count++;
}

int my_put_nbr(int nb)
{
    int output = nb;
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        count++;
        output = -nb;
    }
    if (output < 0) {
        output = -(output / 10);
        my_put_positive(output, &count);
        my_put_positive(-(nb % 10), &count);
    } else
        my_put_positive(output, &count);
    return (0);
}
