/*
** EPITECH PROJECT, 2024
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** src/utils/my_count_files.c
*/

#include "lib.h"
#include "my_ls.h"
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include <time.h>

void my_count_blocks(char *path, lsinfo_t *lsinfo)
{
    struct stat st;
    struct dirent *sd;
    int tot;
    char *str;
    DIR *dir;

    tot = 0;
    dir = opendir(path);
    for (sd = readdir(dir); sd != NULL; sd = readdir(dir)) {
        str = my_strcat(my_strcat(path, "/"), sd->d_name);
        if ((lstat(str, &st)) == 0 && ((sd->d_name[0] != '.') ||
            lsinfo->flags & FLAGS_ALL_FILES))
            tot += st.st_blocks;
    }
    closedir(dir);
    my_printf("total %d\n", tot / 2);
}
