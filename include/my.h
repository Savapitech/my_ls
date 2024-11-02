/*
** EPITECH PROJECT, 2024
** printf
** File description:
** ./include/printf.h
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <ctype.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <unistd.h>
    #include <stdbool.h>

    #define EXIT_ERROR -84
    #define ERROR_OVERFLOW -2
    #define CHAR_TO_DIGIT(c) ((c) & 0xf)
    #define ARRAY_SIZE(array) ((sizeof array) / (sizeof array[0]))
    #define TODO(s) // renvoie rin
    #define ABS(v) (((v) < (0)) ? -(v) : (v))

typedef struct {
    char *str;
    int count;
} buff_t;

typedef struct {
    char *fmt;
    char spec;
    va_list args;
    int width;
    int precision;
    int length;
    int count;
    char flags;
    int written;
    buff_t spec_buff;
    buff_t prefix_buff;
} flags_t;

typedef struct {
    char flag;
    void (*ptr)(flags_t *flags);
} handler_t;

typedef enum {
    FLAGS_ALT_FORM = 1 << 4,
    FLAGS_PAD_ZERO = 1 << 3,
    FLAGS_SET_SPACE = 1 << 2,
    FLAGS_PUT_SIGN = 1 << 1,
    FLAGS_PAD_RIGHT = 1 << 0
} flags_bit_shifts_t;

int my_printf(char *, ...);
char *baby_revstr(char *);
int baby_getnbr(char const *);
int baby_put_nbr(int, flags_t *, int);
int baby_put_hex(size_t nb, flags_t *, int);
int baby_putchar(char);
int baby_putstr(char *);
int baby_stridx(char const *, char);
int baby_strlen(char *);
size_t baby_intlen(size_t truc, int);
int baby_strpnum(char **);
int my_printf(char *, ...);
int printf_parser(char *, va_list);
void printf_put_float(flags_t *);
void printf_put_hex(flags_t *);
void printf_put_nbr(flags_t *);
void printf_put_oct(flags_t *);
void printf_put_pointer(flags_t *);
void printf_put_unsigned_nbr(flags_t *);
void printf_putchar(flags_t *);
void printf_putpercentage(flags_t *);
void printf_putstr(flags_t *);
void printf_put_bin(flags_t *);
void printf_put_hex_upc(flags_t *);
int width_printer(flags_t *, int);
void baby_put_inf(flags_t *);
void baby_put_nan(flags_t *);
char *baby_strcpy(char *, char const *);
void printf_put_scientific(flags_t *);
void baby_put_float(double, flags_t *);
#endif
