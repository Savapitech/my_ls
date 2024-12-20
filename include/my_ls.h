/*
** EPITECH PROJECT, 2024
** CPoolDay08
** File description:
** ./include/my_ls.h
*/

#ifndef MY_H_
    #define MY_H_
    #include "my.h"
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

typedef struct {
    char perms[11];
    char inodes[10];
    buff_t user;
    buff_t group;
    char size[10];
    int rdev;
    __time_t date;
    int timestamp;
    buff_t name;
} ls_buff_t;

typedef struct {
    char *ptr;
    size_t capacity;
    size_t size;
} string_pool_t;

int parser(int, char **);
void my_switch(struct stat *);
void my_switch2(struct stat *);
int my_ls(lsinfo_t *);
int my_lsl(lsinfo_t *);
void my_rights_calc(ls_buff_t *, struct stat *, int);
void my_count_blocks(char *, lsinfo_t *);
int my_count_files(lsinfo_t *);
void my_fill_ls_buff(char *, ls_buff_t *, lsinfo_t *, int);
int compare_time(void const *, void const *);
int compare_time_reverse(void const *, void const *);
#endif
