/*
** get_pos.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/get_pos.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 03 13:46:54 2017 Antoine FORET
** Last update Sat Jun 03 13:46:54 2017 Antoine FORET
*/

#include	<string.h>
#include	"circular_buffer.h"

size_t		arithmetic_pos(t_circular_buffer *self,
				     size_t pos,
				     int movement)
{
  return (self->size + pos + movement) % self->size;
}

ssize_t		size_between(t_circular_buffer *self,
				    size_t start,
				    size_t end)
{
  ssize_t	size;

  size = 0;
  if (start < end)
    size += end - start;
  else if (start > end)
    size += self->size - start + end;
  return (size);
}

ssize_t		circular_buffer_get_pos(t_circular_buffer *self,
					       const char *delimiter)
{
  size_t	pos;
  unsigned int	matched;

  pos = self->read_pos;
  matched = 0;
  while (pos != self->write_pos && delimiter[matched] != '\0')
  {
    if (self->buff[pos] == delimiter[matched])
      matched += 1;
    pos = arithmetic_pos(self, pos, 1);
  }
  return ((delimiter[matched] == '\0') ? size_between(self,
						      self->read_pos,
		      arithmetic_pos(self, pos, (int)(-strlen(delimiter))))
				       : -1);
}