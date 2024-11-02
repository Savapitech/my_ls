/*
** EPITECH PROJECT, 2023
** CPoolDay08
** File description:
** ./include/my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <sys/stat.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include "my.h"

void my_switch(struct stat *);
void my_switch2(struct stat *);
int my_ls(char *);
int my_lsl(char *);
void my_rights_calc(struct stat *);
void my_count_blocks(char *);
#endif
