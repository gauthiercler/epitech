/*
** parse.c for parse in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/tetriminos
** 
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
** 
** Started on  Thu Feb 25 18:31:23 2016 Anas Buyumad
** Last update Thu Mar 17 18:03:44 2016 Gauthier Cler
*/

#include	"tetris.h"

char		*cut_ext(char *name)
{
  char		*res;
  int		i;
  int		j;

  j = 0;
  i = my_strlen(name) - 10;
  if ((res = malloc(sizeof(char) * i + 1)) == NULL)
    return (NULL);
  while (j < i)
    {
      res[j] = name[j];
      j += 1;
    }
  res[j] = '\0';
  return (res);
}

int		check_valid(char *line)
{
  int		i;

  i = 0;
  while (line[i])
    {
      if (line[i] != '*' && line[i] != ' ')
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

int		fill_loop(t_token *token, int i, int fd)
{
  int		j;
  int		k;
  char		*line;
  int		count;

  count = 0;
  j = -1;
  while (++j < (int)token[i].height)
    {
      k = -1;
      if ((line = get_next_line(fd)) == NULL)
	return (ERROR);
      if (check_valid(line) == ERROR)
	return (ERROR);
      (my_strlen(line) == (int)token[i].width) ? count = 1 : 0;
      while (++k < (int)token[i].width)
	{
	  if (line[k] == '\0')
	    token[i].pos_1[j][k] = ' ';
	  else
	    token[i].pos_1[j][k] = line[k];
	}
    }
  return (!(count > 0));
}

int		fill_map(t_token *token, int i, int fd)
{
  int		j;

  j = 0;
  if ((token[i].pos_1 = malloc(sizeof(char *) * token[i].height)) == NULL)
    return (ERROR);
  while (j < (int)token[i].height)
    {
      if ((token[i].pos_1[j] =
	   malloc(sizeof(char) * (token[i].width + 1))) == NULL)
	return (ERROR);
      token[i].pos_1[j][token[i].width] = '\0';
      j += 1;
    }
  if (fill_loop(token, i, fd) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		parse_info(t_token *token, char *line, int i)
{
  int		j;

  if (line[0] < '0' || line[0] > '9')
    return (ERROR);
  while (line[j])
    {
      if ((line[j] < '0' || line[j] > '9') && line[j] != ' ')
	return (ERROR);
      j += 1;
    }
  token[i].width = my_atoi(line);
  while (line[0] >= '0' && line[0] <= '9')
    line++;
  if (line[0] != ' ')
    return (ERROR);
  line++;
  token[i].height = my_atoi(line);
  while (line[0] >= '0' && line[0] <= '9')
    line++;
  if (line[0] != ' ')
    return (ERROR);
  line++;
  token[i].color = my_atoi(line);
  return (SUCCESS);
}
