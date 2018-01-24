#include <unistd.h>
#include <stdlib.h>
#include "../my.h"

char    *add_char_in_line(char *line, char c, int buffer)
{
  int   i;
  char  *new_line;

  i = 0;
  if ((new_line = malloc(sizeof(*new_line) * (my_strlen(line) + buffer))) == NULL)
    return (NULL);
  while (line && line[i])
    {
      new_line[i] = line[i];
      i++;
    }
  new_line[i] = c;
  new_line[++i] = 0;
  if (line != NULL)
    free(line);
  return (new_line);
}

char    *get_next_line(int fd)
{
  char  *line;
  int	r;
  char  c;
  char  s;

  s = '\0';
  line = NULL;
  while ((r = read(fd, &c, 1)) && (c != '\0' && s != '\n'))
    {
      if (c =='\n')
	{
	  if (line != NULL)
	    return (line);
	  else
	    line = "\0";
	  return (line);
	}
      if ((line = add_char_in_line(line, c, BUFFER)) == NULL)
	return (NULL);
      s = c;
    }
  return (line);
}
