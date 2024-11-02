/*
** EPITECH PROJECT, 2023
** B-PSU-100-REN-1-1-myls-savinien.petitjean
** File description:
** src/args/my_lsl.c
*/

#include "lib.h"
#include "my_ls.h"

void my_print_all(struct stat *st, struct dirent *sd, struct passwd *passwd,
    struct group *grp)
{
    my_printf("%*d %s %s %d %s %s\n", 10, st->st_nlink, passwd->pw_name,
        grp->gr_name, st->st_size, my_strpop(ctime(&st->st_mtime), 9),
        sd->d_name);
}

int my_lsl(char *path)
{
    struct stat st;
    struct dirent *sd;
    struct passwd *passwd;
    struct group *grp;
    char *file;
    DIR *dir;

    dir = opendir(path);
    for (sd = readdir(dir); sd != NULL; sd = readdir(dir)) {
        if (sd->d_name[0] != '.') {
            file = my_strcat(my_strcat(path, "/"), sd->d_name);
            stat(file, &st);
            passwd = getpwuid(st.st_uid);
            grp = getgrgid(st.st_gid);
            my_rights_calc(&st);
            my_print_all(&st, sd, passwd, grp);
        }
    }
    closedir(dir);
    return (0);
}
