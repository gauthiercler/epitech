/*
** get_next_line.c for get_next_line in /home/gogo/rendu/CPE_2015_Allum1
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Feb 10 00:15:59 2016 Gauthier Cler
** Last update Wed Feb 10 00:15:59 2016 Gauthier Cler
*/

#include <unistd.h>
#include <stdlib.h>
#include "alu.h"

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE + 1];
  static int	buf_pos = 0;
  char		*save;
  char		*res;
  int		r;

  r = 0;
  res = malloc(sizeof(char) * READ_SIZE + 1);
  if (res == NULL)
    return (res);
  res[READ_SIZE] = '\0';
  while (res[r])
    res[r++] = '\0';
  if (buf_pos != 0)
    if (check_buf(buf, res, &buf_pos) == 1)
      return (res);
  while ((r = read(fd, buf, READ_SIZE)) > 0)
    {
      buf[r] = '\0';
      if ((buf_pos = check_backslash(buf)) == READ_SIZE)
	  res = increase_size(res, buf);
      else
	return (add_slash(buf, res, &buf_pos, save));
    }
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
  save = malloc(sizeof(char) * size + READ_SIZE + 1);
  if (save == NULL)
    return (NULL);
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

char	*add_slash(char *buf, char *res, int *buf_pos, char *save)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (res[i])
    i++;
  if ((save = malloc(sizeof(char) * i + READ_SIZE + 1)) == NULL)
    return (NULL);
  i = -1;
  while (res[++i])
    save[j++] = res[i];
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
