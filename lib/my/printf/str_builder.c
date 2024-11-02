/*
** EPITECH PROJECT, 2024
** printf
** File description:
** string builder
*/

#include "my.h"

int width_printer(flags_t *flags, int printed_count)
{
    int i = 0;
    char pad_char = ' ';

    if ((flags->flags & FLAGS_PAD_RIGHT) && (flags->flags & FLAGS_PAD_ZERO))
        flags->flags &= ~FLAGS_PAD_ZERO;
    if (flags->flags & FLAGS_PAD_ZERO && flags->spec != 'c')
        pad_char = '0';
    for (; i < flags->width - printed_count; i++)
        write(STDOUT_FILENO, &pad_char, sizeof(char));
    return i;
}
