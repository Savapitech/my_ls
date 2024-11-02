/*
** EPITECH PROJECT, 2024
** put_pointer
** File description:
** display the adress given as parameter
** in the hexadecimal format
*/
#include <stdint.h>

#include "my.h"

void printf_put_pointer(flags_t *flags)
{
    size_t src = (size_t)va_arg(flags->args, int *);

    flags->flags |= FLAGS_ALT_FORM;
    baby_put_hex(src, flags, 0);
}
