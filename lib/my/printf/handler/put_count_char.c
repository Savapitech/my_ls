/*
** EPITECH PROJECT, 2024
** countchar
** File description:
** count characters
*/

#include "my.h"

void printf_count_char(flags_t *flags)
{
    int *count = va_arg(flags->args, int *);

    *count = flags->written;
    flags->spec_buff.count = *count;
}
