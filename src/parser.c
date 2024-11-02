/*
** EPITECH PROJECT, 2024
** B-PSU-100-REN-1-1-bsmyls-savinien.petitjean
** File description:
** src/parser.c
*/

#include "lib.h"
#include "my_ls.h"
#include <dirent.h>
#include <errno.h>

static
const char FLAGS[] = "alRdrt";

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

static
void parse_flags(lsinfo_t *lsinfo)
{
    for (int i; *lsinfo->flags_str != '\0'; lsinfo->flags_str++) {
        i = baby_stridx(FLAGS, *lsinfo->flags_str);
        if (i == -1) {
            my_puterr("ls: invalid option -- '");
            write(2, lsinfo->flags_str, 1);
            my_puterr("'\nTry 'ls --help' for more information.\n");
            exit(84);
        }
        lsinfo->flags |= 1 << i;
    }
}

static
void parse_args(lsinfo_t *lsinfo, int i)
{
    if (lsinfo->av[i][0] == '-' && my_strlen(lsinfo->av[i]) > 1) {
        lsinfo->av[i]++;
        lsinfo->flags_str = lsinfo->av[i];
        parse_flags(lsinfo);
    } else if (my_strlen(lsinfo->av[i]) > 0) {
        lsinfo->path = lsinfo->av[i];
        my_error(lsinfo->path);
    }
}

int parser(int ac, char **av)
{
    lsinfo_t lsinfo = { 0, .path = "." };

    lsinfo.ac = ac;
    lsinfo.av = av;
    if (ac > 1) {
        for (int i = 1; i < lsinfo.ac; i++)
            parse_args(&lsinfo, i);
        my_ls(&lsinfo);
    } else
        return my_ls(&lsinfo);
    return 0;
}
