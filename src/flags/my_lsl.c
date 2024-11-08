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
#include <linux/limits.h>
#include <pwd.h>
#include <sys/stat.h>
#include <time.h>

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
void print_ls_buff(lsinfo_t *lsinfo, ls_buff_t *ls_buff, size_t size)
{
    if (lsinfo->flags & FLAGS_TIME_SORT && !(lsinfo->flags & FLAGS_REVERSE))
        mini_qsort((char *)ls_buff, size, sizeof(ls_buff[0]), &compare_time);
    if (lsinfo->flags & FLAGS_TIME_SORT && lsinfo->flags & FLAGS_REVERSE)
        mini_qsort((char *)ls_buff, size, sizeof(ls_buff[0]),
            &compare_time_reverse);
    for (int i = 0; ls_buff[i].name.str; i++) {
        my_printf("%s %s %s %s %s %.16s %s\n", ls_buff[i].perms,
            ls_buff[i].inodes, ls_buff[i].user.str, ls_buff[i].group.str,
            ls_buff[i].size, ctime(&ls_buff[i].date), ls_buff[i].name.str);
    }
}

void my_fill_ls_buff(struct dirent *sd, ls_buff_t *ls_buff,
    lsinfo_t *lsinfo, int i)
{
    struct stat st;
    struct passwd *passwd;
    struct group *grp;
    char *file;

    file = my_strcat(my_strcat(lsinfo->path, "/"), sd->d_name);
    stat(file, &st);
    passwd = getpwuid(st.st_uid);
    grp = getgrgid(st.st_gid);
    my_rights_calc(ls_buff, &st, i);
    ls_buff[i].perms[10] = '\0';
    my_numstr(ls_buff[i].inodes, st.st_nlink);
    ls_buff[i].user.str = passwd ? my_strdup(passwd->pw_name) : "100";
    ls_buff[i].group.str = grp ? my_strdup(grp->gr_name) : "100";
    my_numstr(ls_buff[i].size, st.st_size);
    ls_buff[i].date = st.st_mtime;
    ls_buff[i].timestamp = st.st_mtime;
    ls_buff[i].name.str = my_strdup(sd->d_name);
    ls_buff[i].name.count = my_strlen(sd->d_name);
    free(file);
}

int my_lsl(lsinfo_t *lsinfo)
{
    struct dirent *sd;
    DIR *dir = opendir(lsinfo->path);
    int files_count = my_count_files(lsinfo);
    ls_buff_t ls_buff[files_count + 1];
    int i = 0;

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
