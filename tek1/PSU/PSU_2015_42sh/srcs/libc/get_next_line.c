/*
** get_next_line.c for get_next_line in /home/antoine/lab/CPE/CPE_2015_getnextline/
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue Jan  5 13:18:14 2016 Antoine FORET
** Last update Sun Jun  5 18:31:44 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"libc.h"

/*
** Calc the length of the line
** @params str
** @return i
*/
static int	my_strlen_gnl(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0' && str[i] != '\n')
    i++;
  return (i);
}

/*
** Get the line from the buffer
** @params line, buffer
** @return to_take
*/
static int	get_line_from_buff(char **line, char *buffer)
{
  int		i;
  int		j;
  int		to_take;
  char		*new_line;

  to_take = my_strlen_gnl(buffer);
  i = 0;
  if ((new_line = malloc(my_strlen_gnl(*line) + to_take + 1)) == NULL)
    return (-1);
  while (*line != NULL && (*line)[i] != '\0')
    {
      new_line[i] = (*line)[i];
      i++;
    }
  j = 0;
  while (j < to_take)
    {
      new_line[i + j] = buffer[j];
      j++;
    }
  new_line[i + j] = '\0';
  if (*line != NULL)
    free(*line);
  *line = new_line;
  return (to_take);
}

/*
** Free the static buffer with at the pos
** @params buffer, pos
** @return void
*/
static void	free_buffer(char *buffer, int pos)
{
  int		i;

  i = 0;
  while (buffer[i + pos] != '\0')
    {
      buffer[i] = buffer[i + pos];
      i++;
    }
  while (buffer[i] != '\0')
    buffer[i++] = '\0';
}

/*
** Create the "backslpash_n" line
** @params void
** @return line
*/
static char	*backslpash_n(void)
{
  char		*line;

  line = malloc(1);
  if (line == NULL)
    return (NULL);
  line[0] = '\0';
  return (line);
}

/*
** Get lines in a file descriptor
** @params fd
** @return line
*/
char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  int		pos;
  char		*line;
  int		readed;

  line = NULL;
  readed = 1;
  pos = 0;
  while (buffer[pos] != '\n' && readed > 0)
    {
      if (buffer[pos] == '\0')
	{
	  free_buffer(buffer, READ_SIZE - 1);
	  readed = read(fd, buffer, READ_SIZE);
	  if (readed <= 0)
	    return (line);
	  pos = 0;
	}
      if ((pos += get_line_from_buff(&line, &buffer[pos])) == -1)
	return (NULL);
    }
  if (line == NULL && buffer[pos] == '\n')
    line = backslpash_n();
  free_buffer(buffer, pos + 1);
  return (line);
}
