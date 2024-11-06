/*
** EPITECH PROJECT, 2024
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** src/utils/my_rights_calc.c
*/

#include "lib.h"
#include "my_ls.h"
#include <dirent.h>
#include <grp.h>
#include <pwd.h>

void my_rights_calc(ls_buff_t *ls_buff, struct stat *st, int i)
{
    ls_buff[i].perms[0] = S_ISDIR(st->st_mode) ? 'd' : '-';
    ls_buff[i].perms[1] = st->st_mode & S_IRUSR ? 'r' : '-';
    ls_buff[i].perms[2] = st->st_mode & S_IWUSR ? 'w' : '-';
    ls_buff[i].perms[3] = st->st_mode & S_IXUSR ? 'x' : '-';
    ls_buff[i].perms[4] = st->st_mode & S_IRGRP ? 'r' : '-';
    ls_buff[i].perms[5] = st->st_mode & S_IWGRP ? 'w' : '-';
    if ((st->st_mode & S_ISGID) && !(st->st_mode & S_IXGRP))
        ls_buff[i].perms[6] = 'S';
    else if ((st->st_mode & S_ISGID) && (st->st_mode & S_IXGRP))
        ls_buff[i].perms[6] = 's';
    else
        ls_buff[i].perms[6] = st->st_mode & S_IXGRP ? 'x' : '-';
    ls_buff[i].perms[7] = st->st_mode & S_IROTH ? 'r' : '-';
    ls_buff[i].perms[8] = st->st_mode & S_IWOTH ? 'w' : '-';
    if ((st->st_mode & S_ISVTX) && !(st->st_mode & S_IXOTH))
        ls_buff[i].perms[8] = 'T';
    else if ((st->st_mode & S_ISVTX) && (st->st_mode & S_IXOTH))
        ls_buff[i].perms[8] = 't';
    else
        ls_buff[i].perms[8] = st->st_mode & S_IXOTH ? 'x' : '-';
}
