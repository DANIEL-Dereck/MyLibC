#include <stdlib.h>
#include <unistd.h>
#include "../my.h"

int     my_getnbr(char *str)
{
  int i = 0;
  int nb = 0;
  int sign = 1;

  if (str == NULL)
    return (0);
  while (str[i] && (str[i] == '-' || str[i] == '+'))
    {
      sign *= (str[i] == '-') * -1 + (str[i] == '+');
      ++i;
    }
  
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + (str[i] - 48);
      ++i;
    }

  return (nb * sign);
}

int my_pow(int nbr, int puissance)
{
  int nbrs = nbr;

  if (puissance == 0)
    nbr = 1;
  else if (puissance == 1)
    nbr = nbr;
  else
    while (puissance > 1)
      {
  nbr = nbr * nbrs;
  puissance--;
      }
  return (nbr);
}

int my_put_nbr(int nb)
{
  int a = 1;
  int c = 1;
  int d = nb;
  int e = nb;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      e = nb;
      d = nb;
    }
  while (nb > 9)
    {
      nb = nb / 10;
      a = a * 10;
    }
  while (a > 0)
    {
      e = d / a;
      c = e % 10;
      my_putchar(c + 48);
      a = a / 10;
    }
  return (0);
}

int     my_put_nbr_rec(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 9)
    {
      my_put_nbr_rec(nb / 10);
      my_put_nbr_rec(nb % 10);
    }
  else
    my_putchar(nb + 48);
  return (0);
}

void  my_whileu(unsigned int a, unsigned int c,
      unsigned int d, unsigned int e)
{
  unsigned int nb;
  unsigned int z;

  nb = e;
  z = 0;
  if (nb < z)
    {
      my_putchar('-');
      nb = -nb;
      e = nb;
      d = nb;
    }

  while (nb > 9)
    {
      nb = nb / 10;
      a = a * 10;
    }
  while (a > z)
    {
      e = d / a;
      c = e % 10;
      my_putchar(c + 48);
      a = a / 10;
    }
}

int my_put_nbru(unsigned int nb)
{
  unsigned int a;
  unsigned int c;
  unsigned int d;
  unsigned int e;

  a = 1;
  c = 1;
  d = nb;
  e = nb;
  my_whileu(a, c, d, e);
  return (0);
}

void    my_basewhile(int c, int d, int ba, char *base)
{
  int nb = d;
  int a = 1;
  int e = d;

  while (nb >= ba)
    {
      nb = nb / ba;
      a = a * ba;
    }
  while (a > 0)
    {
      e = d / a;
      c = e % ba;
      my_putchar(base[c]);
      a = a / ba;
    }
}

int     my_putnbr_base(int nb, char *base)
{
  int c;
  int d;
  int ba;

  if (base == NULL)
    return (-1);
  ba = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  c = 1;
  d = nb;
  my_basewhile(c, d, ba, base);
  return (0);
}

int     my_putnbr_base_rec(int nb, char *base)
{
  int   c;

  if (base == NULL)
    return (-1);
  c = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= c)
    {
      my_putnbr_base_rec(nb / c, base);
      my_putnbr_base_rec(nb % c, base);
    }
  else
    my_putchar(base[c]);
  return (0);
}
