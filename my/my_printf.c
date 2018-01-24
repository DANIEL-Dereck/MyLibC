#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"

void	my_formatd(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void	my_formati(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void	my_formatb(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), BINARY);
}

void	my_formato(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), OCTAL);
}

void	my_formatxmin(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), HEXAMIN);
}

void    my_formatxmaj(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), HEXAMAX);
}

void	my_formatp(va_list ap)
{
  my_putstr(OX);
  my_putstr(va_arg(ap, char*));
}

void	my_formatu(va_list ap)
{
  my_put_nbru(va_arg(ap, unsigned int));
}

void	my_formatc(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

void	my_formats(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void	my_formatsmaj(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void	my_printf_func(va_list ap, int f)
{
  void	(*tab[11])(va_list);
  tab[0] = &my_formatd;
  tab[1] = &my_formati;
  tab[2] = &my_formatb;
  tab[3] = &my_formato;
  tab[4] = &my_formatxmin;
  tab[5] = &my_formatxmaj;
  tab[6] = &my_formatp;
  tab[7] = &my_formatu;
  tab[8] = &my_formatc;
  tab[9] = &my_formats;
  tab[10] = &my_formatsmaj;
  tab[f](ap);
}

char	*my_printformat(char *my_formatall)
{
  my_formatall[0] = 'd';
  my_formatall[1] = 'i';
  my_formatall[2] = 'b';
  my_formatall[3] = 'o';
  my_formatall[4] = 'x';
  my_formatall[5] = 'X';
  my_formatall[6] = 'p';
  my_formatall[7] = 'u';
  my_formatall[8] = 'c';
  my_formatall[9] = 's';
  my_formatall[10] = 'S';
  return (my_formatall);
}

void	my_printf_funk(const char *format, char *my_formatall, va_list ap)
{
  int	a;
  int	f;

  f = 0;
  a = 0;
  while (format[a] != '\0')
    {
      if (format[a] == '%')
	{
	  while (my_formatall[f] != format[a + 1] && my_formatall[f] != 0)
	    f = f + 1;
	  if (format[a + 1] == my_formatall[f])
	    my_printf_func(ap, f);
	  else
	    {
	      my_putchar('%');
	      my_putchar(a + 1);
	    }
	  a = a + 2;
	  f = 0;
	}
      my_putchar(format[a]);
      a = a + 1;
    }
  free(my_formatall);
}

int	my_printf(const char *format, ...)
{
  va_list ap;
  char *my_formatall;

    my_formatall = malloc(sizeof(my_formatall) * 11);
  if (my_formatall == NULL)
    return (-1);
  if (format == NULL)
    return (-1);
  va_start(ap, format);
  my_formatall = my_printformat(my_formatall);
  my_printf_funk(format, my_formatall, ap);
  va_end(ap);
  return (0);
}
