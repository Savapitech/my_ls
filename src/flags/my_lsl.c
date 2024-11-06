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

static
void print_ls_buff(ls_buff_t *ls_buff)
{
    for (int i = 0; ls_buff[i].name.str; i++) {
        my_printf("%s %s %s %s %s %.16s %s\n", ls_buff[i].perms,
            ls_buff[i].inodes, ls_buff[i].user.str, ls_buff[i].group.str,
            ls_buff[i].size, ls_buff[i].date.str, ls_buff[i].name.str);
    }
}

static
void my_print_all(struct dirent *sd, ls_buff_t *ls_buff,
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
    ls_buff[i].user.str = my_strdup(passwd->pw_name);
    ls_buff[i].group.str = my_strdup(grp->gr_name);
    my_numstr(ls_buff[i].size, st.st_size);
    ls_buff[i].date.str = ctime(&st.st_mtime);
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
            my_print_all(sd, ls_buff, lsinfo, i);
            i++;
        }
    }
    ls_buff[i].name.str = NULL;
    print_ls_buff(ls_buff);
    closedir(dir);
    return (0);
}
