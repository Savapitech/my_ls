/*
** EPITECH PROJECT, 2024
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** src/flags/my_lsl.c
*/

#include "lib.h"
#include "my_ls.h"

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include <time.h>

int my_ls(lsinfo_t *lsinfo)
{
    struct dirent *sd;
    DIR *dir;

    if (lsinfo->flags & FLAGS_LONG_LISTING) {
        my_count_blocks(lsinfo->path);
        return (my_lsl(lsinfo));
    }
    dir = opendir(lsinfo->path);
    for (sd = readdir(dir); sd != NULL; sd = readdir(dir))
        if (sd->d_name[0] != '.' || lsinfo->flags & FLAGS_ALL_FILES)
            my_printf("%s  ", sd->d_name);
    closedir(dir);
    my_printf("\n");
    return (0);
}
