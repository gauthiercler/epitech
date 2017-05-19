/*
** get_next_line.c for tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Mar 18 18:43:42 2016 Anas Buyumad
** Last update Thu May 19 15:26:09 2016 montag_v
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"raytracer.h"

static char	*next_line(const int fd, char *buffer, char *old, int *inc)
{
  char		*new;
  int		length;
  int		i;

  i = 0;
  old[inc[0]] = '\0';
  length = str_len(old);
  if ((new = bunny_malloc(length + READ_SIZE + 2)) == 0)
    return (NULL);
  while (i < length)
    {
      new[i] = old[i];
      i += 1;
    }
  if (old != NULL)
    bunny_free(old);
  inc[1] = read(fd, buffer, READ_SIZE);
  if (inc[1] <= READ_SIZE)
    buffer[inc[1]] = '\0';
  return (new);
}

static int	read_buffer(const int fd, char *buffer, int *inc, int *pos)
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
  if ((s = bunny_malloc(READ_SIZE + 1)) == 0)
    return (NULL);
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
