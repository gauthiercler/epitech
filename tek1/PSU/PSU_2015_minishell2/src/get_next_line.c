/*
** get_next_line.c for get_next_line in /home/gauthier/rendu/CPE_2015_getnextline
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan  4 09:43:37 2016 Gauthier Cler
** Last update Sun Apr  3 20:38:12 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"mysh.h"

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE + 1];
  static int	buf_pos = 0;
  char		*res;
  int		r;

  r = 0;
  res = xmalloc(sizeof(char) * READ_SIZE + 1);
  my_bzero(res, READ_SIZE);
  if (buf_pos != 0)
    if (check_buf(buf, res, &buf_pos) == 1)
      return (res);
  while ((r = read(fd, buf, READ_SIZE)) > 0)
    {
      buf[r] = '\0';
      if ((buf_pos = check_backslash(buf)) == READ_SIZE)
	  res = increase_size(res, buf);
      else
	return (add_slash(buf, res, &buf_pos));
    }
  free(res);
  return (NULL);
}

char		*increase_size(char *res, char *buf)
{
  int		i;
  int		j;
  int		size;
  char		*save;

  j = 0;
  size = 0;
  while (res[size])
    size++;
  save = xmalloc(sizeof(char) * size + READ_SIZE + 1);
  save[READ_SIZE + size]  = '\0';
  i = 0;
  while (res[i])
    {
      save[j] = res[i];
      j++;
      i++;
    }
  i = 0;
  while (buf[i])
    save[j++] = buf[i++];
  free(res);
  return (save);
}

char	*add_slash(char *buf, char *res, int *buf_pos)
{
  int	i;
  int	j;
  char	*save;

  init_couple(&i, &j);
  while (res[i])
    i++;
  save = xmalloc(sizeof(char) * i + READ_SIZE + 1);
  my_strcpy(res, save);
  free(res);
  i = 0;
  while (buf[i])
    {
      if (buf[i] == '\n')
	{
	  *buf_pos = i + 1;
	  save[j] = '\0';
	  return (save);
	}
      save[j++] = buf[i++];
    }
  save[j] = '\0';
  return (save);
}

int	check_backslash(char *buf)
{
  int	i;

  i = 0;
  while (buf[i])
    {
      if (buf[i] == '\n')
	return (i);
      i++;
    }
  return (i);
}

int	check_buf(char *buf, char *res, int *buf_pos)
{
  int	i;
  int	j;

  j = 0;
  i = *buf_pos;
  while (buf[i])
    {
      if (buf[i] == '\n')
	{
	  *buf_pos = i + 1;
	  return (1);
	}
      res[j] = buf[i];
      j++;
      i++;
    }
  j++;
  res[j] = '\0';
  return (0);
}
