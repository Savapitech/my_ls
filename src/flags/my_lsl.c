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
#include <linux/limits.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>
#include <stdio.h>

int compare_time(void const *a, void const *b)
{
    ls_buff_t *lsbuff_a = (ls_buff_t *)a;
    ls_buff_t *lsbuff_b = (ls_buff_t *)b;

    return lsbuff_b->timestamp - lsbuff_a->timestamp;
}

int compare_time_reverse(void const *a, void const *b)
{
    ls_buff_t *lsbuff_a = (ls_buff_t *)a;
    ls_buff_t *lsbuff_b = (ls_buff_t *)b;

    return lsbuff_a->timestamp - lsbuff_b->timestamp;
}

static
void printf_lsl_buff3(lsinfo_t *lsinfo, char **dirs, int dir_count,
    char *old_path)
{
    if (lsinfo->flags & FLAGS_RECURSIVE) {
        for (int i = 0; i < dir_count; i++) {
            my_printf("\n");
            lsinfo->path = my_strcat(my_strcat(old_path,
                my_strcmp(old_path, "/") ? "/" : ""), dirs[i]);
            my_lsl(lsinfo);
        }
    }
}

static
void print_with_devs(ls_buff_t *ls_buff, int i)
{
    char majordev[10];
    char minordev[10];

    my_numstr(majordev, major(ls_buff[i].rdev));
    my_numstr(minordev, minor(ls_buff[i].rdev));
    my_printf("%s %s %s %s %s, %s %.16s %s\n", ls_buff[i].perms,
        ls_buff[i].inodes, ls_buff[i].user.str, ls_buff[i].group.str,
        majordev, minordev, ctime(&ls_buff[i].date), ls_buff[i].name.str);
}

static
void print_lsl_buff2(lsinfo_t *lsinfo, ls_buff_t *ls_buff)
{
    int dir_count = 0;
    char *dirs[255] = { NULL };
    char *old_path = my_strdup(lsinfo->path);

    for (int i = 0; ls_buff[i].name.str; i++) {
        if (baby_stridx("bc", ls_buff[i].perms[0]) != -1)
            print_with_devs(ls_buff, i);
        else
            my_printf("%s %s %s %s %s %.16s %s\n", ls_buff[i].perms,
                ls_buff[i].inodes, ls_buff[i].user.str, ls_buff[i].group.str,
                ls_buff[i].size, ctime(&ls_buff[i].date), ls_buff[i].name.str);
        if (lsinfo->flags & FLAGS_RECURSIVE && ls_buff[i].perms[0] == 'd' &&
            my_strcmp(ls_buff[i].name.str, "..") &&
            my_strcmp(ls_buff[i].name.str, ".")) {
            dirs[dir_count] = my_strdup(ls_buff[i].name.str);
            dir_count++;
        }
    }
    printf_lsl_buff3(lsinfo, dirs, dir_count, old_path);
}

static
void print_lsl_buff(lsinfo_t *lsinfo, ls_buff_t *ls_buff, size_t size)
{
    if (lsinfo->flags & FLAGS_TIME_SORT && !(lsinfo->flags & FLAGS_REVERSE))
        mini_qsort((char *)ls_buff, size, sizeof(ls_buff[0]), &compare_time);
    if (lsinfo->flags & FLAGS_TIME_SORT && lsinfo->flags & FLAGS_REVERSE)
        mini_qsort((char *)ls_buff, size, sizeof(ls_buff[0]),
            &compare_time_reverse);
    if (lsinfo->flags & FLAGS_RECURSIVE)
        my_printf("%s:\n", lsinfo->path);
    my_count_blocks(lsinfo->path, lsinfo);
    print_lsl_buff2(lsinfo, ls_buff);
}

void my_fill_ls_buff(char *name, ls_buff_t *ls_buff,
    lsinfo_t *lsinfo, int i)
{
    struct stat st;
    struct passwd *passwd;
    struct group *grp;
    char *file = my_strcmp(lsinfo->path, name) == 0 ? name :
        my_strcat(my_strcat(lsinfo->path, "/"), name);

    stat(file, &st);
    passwd = getpwuid(st.st_uid);
    grp = getgrgid(st.st_gid);
    my_rights_calc(ls_buff, &st, i);
    ls_buff[i].perms[10] = '\0';
    my_numstr(ls_buff[i].inodes, st.st_nlink);
    ls_buff[i].user.str = passwd ? my_strdup(passwd->pw_name) : "100";
    ls_buff[i].group.str = grp ? my_strdup(grp->gr_name) : "100";
    my_numstr(ls_buff[i].size, st.st_size > 0 ? st.st_size : 0);
    ls_buff[i].rdev = st.st_rdev;
    ls_buff[i].date = st.st_mtime;
    ls_buff[i].timestamp = st.st_mtime;
    ls_buff[i].name.str = my_strdup(name);
    ls_buff[i].name.count = my_strlen(name);
}

static
int fill_lsl(lsinfo_t *lsinfo, ls_buff_t *ls_buff, DIR *dir)
{
    int i = 0;
    struct dirent *sd;

    for (sd = readdir(dir); sd != NULL; sd = readdir(dir)) {
        if ((sd->d_name[0] != '.' || lsinfo->flags & FLAGS_ALL_FILES)) {
            my_fill_ls_buff(sd->d_name, ls_buff, lsinfo, i);
            i++;
        }
    }
    return i;
}

int my_lsl(lsinfo_t *lsinfo)
{
    DIR *dir = opendir(lsinfo->path);
    int files_count = my_count_files(lsinfo);
    ls_buff_t ls_buff[files_count + 1];
    int i = 0;

    if (dir != NULL)
        i = fill_lsl(lsinfo, ls_buff, dir);
    else if (errno == ENOTDIR) {
        my_fill_ls_buff(lsinfo->path, ls_buff, lsinfo, i);
        i++;
    } else
        return (0);
    ls_buff[i].name.str = NULL;
    print_lsl_buff(lsinfo, ls_buff, files_count);
    closedir(dir);
    return (0);
}
