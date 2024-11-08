/*
** EPITECH PROJECT, 2024
** day6
** File description:
** day06.h
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <ctype.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "my.h"
    #define IDX_OF(array, i, mem_s) (array + ((i) * (mem_s)))

int my_get_array_size(char **);
int my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
int my_put_unsigned_nbr(unsigned int);
int my_put_hexa(int);
int my_put_address(int);
int my_put_hexa_upper(int);
int my_put_octal(int);
void my_swap(int *, int *);
int my_put_float(float);
int my_put_float_upper(float);
void my_put_float2(int *, int, int, int);
void my_put_float2_upper(int *, int, int, int);
int my_putstr(char const *);
int my_puterr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(void);
char *my_strshift(char *, int);
int my_showstr(char const *);
int my_showmem(char const *, int);
int my_show_word_array(char *const *);
char **my_str_to_word_array(char const *);
int my_getnbr(char const *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);
char *my_strpop(char *, int);
int my_char_isalpha(char);
int my_char_isnum(char);
int my_str_isalphanum(char *);
void my_freestr(char **);
int my_strlen(char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char *);
int my_str_isnum(char *);
int my_str_islower(char *);
int my_str_isupper(char *);
int my_str_isprintable(char *);
void *my_memcpy(uint8_t *, uint8_t const *, size_t);
void *my_realloc(void *, size_t, size_t);
char *my_numstr(char *, int);
void mini_qsort(char *, size_t, size_t,
    int compare(void const *, void const *));
#endif /* LIB_H_ */
