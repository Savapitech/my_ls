/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** src/args/my_lsl.c
*/

#include "lib.h"
#include "my_ls.h"

int my_ls(char *path)
{
    struct dirent *sd;
    DIR *dir;

    dir = opendir(path);
    for (sd = readdir(dir); sd != NULL; sd = readdir(dir)) {
        if (sd->d_name[0] != '.')
            my_printf("%s  ", sd->d_name);
    }
    closedir(dir);
    my_printf("\n");
    return (0);
}
