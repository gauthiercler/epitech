/*
** get_next_line.c for get_next_line in /home/gogo/rendu/dante/profondeur/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:06:56 2016 Gauthier Cler
** Last update Wed Apr 27 23:26:31 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"solver.h"

char		*next_line(const int fd, char *buffer, char *old, int *inc)
{
  char		*new;
  int		length;
  int		i;

  i = 0;
  old[inc[0]] = '\0';
  length = str_len(old);
  new = xmalloc(length + READ_SIZE + 2);
  while (i < length)
    {
      new[i] = old[i];
      i += 1;
    }
  free(old);
  inc[1] = read(fd, buffer, READ_SIZE);
  if (inc[1] <= READ_SIZE)
    buffer[inc[1]] = '\0';
  return (new);
}

int		read_buffer(const int fd, char *buffer, int *inc, int *pos)
{
  if (buffer[*pos] == '\0')
    {
      inc[1] = read(fd, buffer, READ_SIZE);
      if (inc[1] > 0 && inc[1] < READ_SIZE)
	buffer[inc[1]] = '\0';
      if (inc[1] <= 0)
	return (0);
      else
	*pos = 0;
      return (1);
    }
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  static int	pos = 0;
  char		*s;
  int		inc[2];

  inc[0] = 0;
  s = NULL;
  if (read_buffer(fd, buffer, inc, &pos) == 0)
    return (NULL);
  s = xmalloc(READ_SIZE + 1);
  while (buffer[pos] != '\n' && buffer[pos] != '\0')
    {
      s[inc[0]++] = buffer[pos++];
      if (pos == READ_SIZE)
	{
	  if ((s = next_line(fd, buffer, s, inc)) == 0)
	    return (NULL);
	  pos = 0;
	}
    }
  s[inc[0]] = '\0';
  if (buffer[pos] == '\n')
    pos += 1;
  return (s);
}
