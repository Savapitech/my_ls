/*
** EPITECH PROJECT, 2024
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** src/utils/my_count_files.c
*/

#include "my_ls.h"
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include <time.h>

int my_count_files(lsinfo_t *lsinfo)
{
    int count = 0;
    DIR *dir = opendir(lsinfo->path);
    struct dirent *sd;

    if (dir == NULL)
        return 0;
    for (sd = readdir(dir); sd != NULL; sd = readdir(dir))
        if (sd->d_name[0] != '.' || lsinfo->flags & FLAGS_ALL_FILES)
            count++;
    closedir(dir);
    return count;
}
