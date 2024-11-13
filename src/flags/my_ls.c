/*
** EPITECH PROJECT, 2024
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** src/flags/my_lsl.c
*/

#include "lib.h"
#include "my_ls.h"

#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <sys/stat.h>
#include <time.h>

static
void printf_ls_buff3(lsinfo_t *lsinfo, char **dirs, int dir_count,
    char *old_path)
{
    if (lsinfo->flags & FLAGS_RECURSIVE) {
        for (int i = 0; i < dir_count; i++) {
            my_printf("\n");
            lsinfo->path = my_strcat(my_strcat(old_path,
                my_strcmp(old_path, "/") ? "/" : ""), dirs[i]);
            my_ls(lsinfo);
        }
    }
}

static
void print_ls_buff2(lsinfo_t *lsinfo, ls_buff_t *ls_buff)
{
    int dir_count = 0;
    char *dirs[255] = { NULL };
    char *old_path = my_strdup(lsinfo->path);

    for (int i = 0; ls_buff[i].name.str; i++) {
        my_printf("%s ", ls_buff[i].name.str);
        if (lsinfo->flags & FLAGS_RECURSIVE && ls_buff[i].perms[0] == 'd' &&
            my_strcmp(ls_buff[i].name.str, "..") &&
            my_strcmp(ls_buff[i].name.str, ".")) {
            dirs[dir_count] = my_strdup(ls_buff[i].name.str);
            dir_count++;
        }
    }
    my_printf("\n");
    printf_ls_buff3(lsinfo, dirs, dir_count, old_path);
}

static
void print_ls_buff(lsinfo_t *lsinfo, ls_buff_t *ls_buff, size_t size, int i)
{
    ls_buff[i].name.str = NULL;
    if (lsinfo->flags & FLAGS_TIME_SORT && !(lsinfo->flags & FLAGS_REVERSE))
        mini_qsort((char *)ls_buff, size, sizeof(ls_buff[0]), &compare_time);
    if (lsinfo->flags & FLAGS_TIME_SORT && lsinfo->flags & FLAGS_REVERSE)
        mini_qsort((char *)ls_buff, size, sizeof(ls_buff[0]),
            &compare_time_reverse);
    if (lsinfo->flags & FLAGS_RECURSIVE)
        my_printf("%s:\n", lsinfo->path);
    print_ls_buff2(lsinfo, ls_buff);
}

int my_ls(lsinfo_t *lsinfo)
{
    struct dirent *sd;
    DIR *dir = opendir(lsinfo->path);
    int files_count = my_count_files(lsinfo);
    ls_buff_t ls_buff[files_count + 1];
    int i = 0;

    if (lsinfo->flags & FLAGS_LONG_LISTING)
        return (my_lsl(lsinfo));
    if (errno == ENOTDIR)
        return (my_printf("%s\n", lsinfo->path));
    if (dir == NULL)
        return 0;
    for (sd = readdir(dir); sd != NULL; sd = readdir(dir)) {
        if ((sd->d_name[0] != '.' || lsinfo->flags & FLAGS_ALL_FILES)) {
            my_fill_ls_buff(sd->d_name, ls_buff, lsinfo, i);
            i++;
        }
    }
    print_ls_buff(lsinfo, ls_buff, files_count, i);
    return (closedir(dir));
}
