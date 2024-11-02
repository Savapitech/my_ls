/*
** EPITECH PROJECT, 2024
** CPoolDay08
** File description:
** ./include/my_ls.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <dirent.h>
    #include <grp.h>
    #include <pwd.h>
    #include <stdint.h>
    #include <sys/stat.h>

typedef struct {
    int ac;
    char **av;
    char *path;
    char *flags_str;
    uint8_t flags;
} lsinfo_t;

typedef enum {
    FLAGS_ALL_FILES = 1 << 0,
    FLAGS_LONG_LISTING = 1 << 1,
    FLAGS_RECURSIVE = 1 << 2,
    FLAGS_DIRECTORY = 1 << 3,
    FLAGS_REVERSE = 1 << 4,
    FLAGS_TIME_SORT = 1 << 5
} flags_shifts_t;

int parser(int, char **);
void my_switch(struct stat *);
void my_switch2(struct stat *);
int my_ls(lsinfo_t *);
int my_lsl(lsinfo_t *);
void my_rights_calc(struct stat *);
void my_count_blocks(char *);
#endif
