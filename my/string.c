#include <stdlib.h>
#include "../my.h"

char    *my_remp_str(char *str, char *dest, int i, int k)
{
  i = 0;
  k = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
        {
          while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
            i++;
          dest[k++] = str[i++];
        }
      else
        dest[k++] = str[i++];
    }
  dest[k] = '\0';
  return (dest);
}

char    *my_epur_str(char *str)
{
  char *dest;
  int k = 0;
  int i = 0;
  
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
          i++;
      else
        i++;
      k++;
    }
  if ((dest = malloc(sizeof(*dest) * (k + 1))) == NULL)
    return (NULL);
  dest = my_remp_str(str, dest, i, k);
  return (dest);
}

int     my_needposchar(char *str, char c)
{
  int r = 0;

  if (str == NULL)
    return (-1);
  while (str[r] != '\0')
    {
      if (str[r] == c)
        return (r);
      r = r + 1;
    }
  return (-1);
}

int     my_needposcharAt(char *str, char c, int start)
{
  int r = start;
  
  if (my_strlen(str) - start <= 0)
    return(-1);
  if (str == NULL)
    return (-1);
  while (str[r] != '\0')
    {
      if (str[r] == c)
        return (r);
      r = r + 1;
    }
  return (-1);
}

int my_nmatch_bis(char *s1, char *s2, int pos)
{
  int i = 0;

  if (pos > my_strlen(s2))
    return (-1);
  while (i <= pos)
    {
      if (s1[i] != s2[i])
  return (-1);
      i++;
    }
  return (0);
}

int my_nmatch(char *s1, char *s2, int pos)
{
  int len1 = my_strlen(s1);
  int len2 = my_strlen(s2);
  int result = 0;

  if (pos <= 0 || s1 == NULL || s2 == NULL)
    return (-1);
  if (len1 >= len2)
    result = my_nmatch_bis(s1, s2, pos);
  else
    result = my_nmatch_bis(s2, s1, pos);
  return (result);
}

void  my_putchar(char c)
{
  write(1, &c, 1);
}

int my_putstr(char *str)
{
  int a = 0;

  if (str != NULL)
    {
      while (str[a] != '\0')
  {
    my_putchar(str[a]);
    a += 1;
  }
      return (0);
    }
  return (-1);
}

int my_revstr(char *str)
{
  int i = 0;

  if (str != NULL)
    {
      while (str[i++] != '\0');
      i--;
      while (i != 0)
  my_putchar(str[i--]);
      return (0);
    }
  return (-1);
}

int my_c_w(char *str)
{
  int   i = 0;
  int   n = 1;

  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

int my_c_c(char *str)
{
  int i = 0;

  while ((str[i] != ' ') && (str[i] != '\0') && (str[i] != '\n'))
    i++;
  i = i + 1;
  return (i);
}

char  **my_str_wordtab(char *str, int a, int b)
{
  char  **tab;
  int   i = 0;

  if ((tab = malloc(sizeof(tab) * ((my_c_w(str) + 1)))) == NULL)
    return (NULL);
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        {
          while (str[i++] == ' ');
    i--;
          a++;
          b = 0;
        }
      if ((tab[a] = malloc(sizeof(*tab) * ((my_c_c(str + i) + 1)))) == NULL)
  return (NULL);
      while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
        tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = NULL;
  return (tab);
}

char  **my_str_to_wordtab(char *str)
{
  char **tab;
  int a = 0;
  int b = 0;

  if (str == NULL)
    return (NULL);
  if ((tab = my_str_wordtab(str, a, b)) == NULL)
    return (NULL);
  return (tab);
}

char    *my_strcat(char *src, char *str)
{
  char *dest;
  int a = my_strlen(src);
  int b = my_strlen(str);
  int i = 0;
  int l = 0;

  if ((dest = malloc(sizeof(*dest) * (a + b))) == NULL)
    return (0);
  while (a >= 0)
    {
      dest[i] = src[i];
      i++;
      a--;
    }
  l = i;
  while (b >= 0)
    {
      dest[l++] = str[i++];
      b--;
    }
  return (dest);
}

int     my_strcmp(char *s1, char *s2)
{
  int b = my_strlen(s1);
  int c = my_strlen(s2);

  if (s1 == NULL || s2 == NULL)
    return (-1);
  if (b != c)
    return (-1);
  b = 0;
  while (s1[b] != '\0')
    {
      if (s1[b] != s2[b])
        return (-1);
      b++;
    }
  return (0);
}

char    *my_strdup(char *src)
{
  char  *dest;
  int r = 0;

  r = 0;
  if (src == NULL)
    return (NULL);
  while (src[r++] != '\0');
  if ((dest = malloc(sizeof(dest) * r)) == NULL)
    return (NULL);
  r = 0;
  while (src[r] != '\0')
    {
      dest[r] = src[r];
      r = r + 1;
    }
  dest[r] = '\0';
  return (dest);
}

int my_strlen(char *str)
{
  int result = 0;

  if (str != NULL) {
    while (str[result++] != '\0');
  }
  
  return (--result);
}
