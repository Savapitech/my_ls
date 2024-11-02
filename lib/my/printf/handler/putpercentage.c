/*
** EPITECH PROJECT, 2024
** point_exa
** File description:
** display the adress in hexa
*/

#include "my.h"

void printf_putpercentage(flags_t *flags)
{
    (void)flags;
    flags->width = 0;
    flags->spec_buff.str = "%";
    flags->spec_buff.count = 1;
}
