/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-bsmyls-savinien.petitjean
** File description:
** src/main.c
*/

#include "lib.h"
#include "my_ls.h"
#include <dirent.h>
#include <errno.h>

void my_error(char *path)
{
    DIR *dir;

    dir = opendir(path);
    if (dir == NULL) {
        if (errno == EACCES) {
            my_puterr("ls: cannot open directory '");
            my_puterr(path);
            my_puterr("': Permission denied\n");
            exit(84);
        }
        my_puterr("ls: cannot access '");
        my_puterr(path);
        my_puterr("': No such file or directory\n");
        exit(84);
    }
}

void my_print_one_arg(char *name)
{
    if (name[0] != '.')
        my_printf("%s  ", name);
}

int my_other_args(int ac, char *av[])
{
    if (my_strcmp(av[1], "-l") == 0) {
        if (ac == 2) {
            my_count_blocks(".");
            my_lsl(".");
            return (0);
        }
        for (int i = 2; i < ac; i++) {
            my_error(av[i]);
            my_count_blocks(av[i]);
            my_lsl(av[i]);
        }
        return (0);
    }
    for (int i = 1; i < ac; i++) {
        my_error(av[i]);
        my_ls(av[i]);
    }
    return (0);
}

int main(int ac, char *av[])
{
    struct dirent *sd;
    DIR *dir;

    if (ac == 1) {
        dir = opendir(".");
        for (sd = readdir(dir); sd != NULL; sd = readdir(dir))
            my_print_one_arg(sd->d_name);
        closedir(dir);
        my_printf("\n");
        return (0);
    }
    my_other_args(ac, av);
    return (0);
}
