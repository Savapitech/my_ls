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

static
void print_ls_buff(lsinfo_t *lsinfo, ls_buff_t *ls_buff, size_t size)
{
    if (lsinfo->flags & FLAGS_TIME_SORT && !(lsinfo->flags & FLAGS_REVERSE))
        mini_qsort((char *)ls_buff, size, sizeof(ls_buff[0]), &compare_time);
    if (lsinfo->flags & FLAGS_TIME_SORT && lsinfo->flags & FLAGS_REVERSE)
        mini_qsort((char *)ls_buff, size, sizeof(ls_buff[0]),
            &compare_time_reverse);
    for (int i = 0; ls_buff[i].name.str; i++)
        my_printf("%s  ", ls_buff[i].name.str);
    my_printf("\n");
}

int my_ls(lsinfo_t *lsinfo)
{
    struct dirent *sd;
    DIR *dir = opendir(lsinfo->path);
    int files_count = my_count_files(lsinfo);
    ls_buff_t ls_buff[files_count + 1];
    int i = 0;

    if (lsinfo->flags & FLAGS_LONG_LISTING) {
        my_count_blocks(lsinfo->path, lsinfo);
        return (my_lsl(lsinfo));
    }
    for (sd = readdir(dir); sd != NULL; sd = readdir(dir)) {
        if ((sd->d_name[0] != '.' || lsinfo->flags & FLAGS_ALL_FILES)) {
            my_fill_ls_buff(sd, ls_buff, lsinfo, i);
            i++;
        }
    }
    ls_buff[i].name.str = NULL;
    print_ls_buff(lsinfo, ls_buff, files_count);
    closedir(dir);
    return (0);
}
