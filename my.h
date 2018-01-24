#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define BINARY "01"
#define HEXAMIN "01234567899abcdef"
#define HEXAMAX "01234567899ABCDEF"
#define OCTAL "01234567"
#define OX "0x"
#define BUFFER 2


/* my_printf */
void    my_printf_func(va_list ap, int f);
char    *my_printformat(char *my_formatall);
void    my_printf_funk(const char *format, char *my_formatall, va_list ap);
int	    my_printf(const char *format, ...);
void    my_formatd(va_list ap);
void    my_formati(va_list ap);
void    my_formatb(va_list ap);
void    my_formato(va_list ap);
void    my_formatxmin(va_list ap);
void    my_formatxmaj(va_list ap);
void    my_formatp(va_list ap);
void    my_formatu(va_list ap);
void    my_formats(va_list ap);
void    my_formatc(va_list ap);
void    my_formatsmaj(va_list ap);

/* number */
int     my_getnbr(char *str);
void    my_basewhile(int c, int d, int ba, char *base);
int     my_putnbr_base(int nb, char *base);
void    my_while(int a, int c, int d, int e);
int     my_put_nbr(int nb);
void    my_whileu(unsigned int a, unsigned int c, unsigned int d, unsigned int e);
int     my_put_nbru(unsigned int nb);
int     my_putnbr_base_rec(int nb, char *base);
int     my_put_nbr_rec(int nb);
int     my_pow(int nbr, int puissance);

/* string */
char    *add_char_in_line(char *line, char c, int buffer);
char    *get_next_line(int fd);
int     my_needposchar(char *str, char c);
int     my_putstr(char *str);
char    *my_strdup(char *src);
char    *my_strcat(char *src, char *str);
int     my_nmatch_bis(char *s1, char *s2, int pos);
int     my_nmatch(char *s1, char *s2, int pos);
int     my_revstr(char *str);
int     my_strlen(char *str);
char    *my_remp_str(char *str, char *dest, int i, int k);
char    *my_epur_str(char *str);
void    my_putchar(char c);
int     my_strcmp(char *s1, char *s2);
int     my_c_w(char *str);
int     my_c_c(char *str);
char    **my_str_wordtab(char *str, int a, int b);
char    **my_str_to_wordtab(char *str);
int     my_needposcharAt(char *str, char c, int start);

#endif
