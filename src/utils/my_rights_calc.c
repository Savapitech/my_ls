/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** src/utils/my_rights_calc.c
*/

#include "lib.h"
#include "my_ls.h"

void my_rights_calc(struct stat *st)
{
    my_printf(S_ISDIR(st->st_mode) ? "d" : "-");
    my_printf(st->st_mode & S_IRUSR ? "r" : "-");
    my_printf(st->st_mode & S_IWUSR ? "w" : "-");
    my_printf(st->st_mode & S_IXUSR ? "x" : "-");
    my_printf(st->st_mode & S_IRGRP ? "r" : "-");
    my_printf(st->st_mode & S_IWGRP ? "w" : "-");
    if ((st->st_mode & S_ISGID) && !(st->st_mode & S_IXGRP))
        my_printf("S");
    else if ((st->st_mode & S_ISGID) && (st->st_mode & S_IXGRP))
        my_printf("s");
    else
        my_printf((st->st_mode & S_IXGRP) ? ("x") : ("-"));
    my_printf(st->st_mode & S_IROTH ? "r" : "-");
    my_printf(st->st_mode & S_IWOTH ? "w" : "-");
    if ((st->st_mode & S_ISVTX) && !(st->st_mode & S_IXOTH))
        my_printf("T ");
    else if ((st->st_mode & S_ISVTX) && (st->st_mode & S_IXOTH))
        my_printf("t ");
    else
        my_printf((st->st_mode & S_IXOTH) ? ("x ") : ("- "));
}
