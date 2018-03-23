# MyLibC

Function:

Like real printf.
int	    my_printf(const char *format, ...);

Number
int     my_getnbr(char *str);
int     my_putnbr_base(int nb, char *base);
int     my_put_nbr(int nb);
int     my_put_nbru(unsigned int nb);
int     my_putnbr_base_rec(int nb, char *base);
int     my_put_nbr_rec(int nb);
int     my_pow(int nbr, int puissance);

String
char    *get_next_line(int fd);
void    my_putchar(char c);
int     my_putstr(char *str);
char    *my_strdup(char *src);
char    *my_strcat(char *src, char *str);
int     my_strcmp(char *s1, char *s2);
int     my_revstr(char *str);
int     my_strlen(char *str);
char    *my_epur_str(char *str);
char    **my_str_to_wordtab(char *str);
int     my_nmatch_bis(char *s1, char *s2, int pos);
int     my_nmatch(char *s1, char *s2, int pos);
int     my_needposchar(char *str, char c);
int     my_needposcharAt(char *str, char c, int start);
