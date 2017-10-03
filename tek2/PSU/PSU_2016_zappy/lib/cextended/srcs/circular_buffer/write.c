/*
** write.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/write.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 19:55:53 2017 Antoine FORET
** Last update Wed May 31 19:55:53 2017 Antoine FORET
*/

#include	<string.h>
#include	"circular_buffer.h"

static void	write_end(t_circular_buffer *self,
			     const char **buff,
			     size_t *size)
{
  size_t	to_write;

  to_write = self->size - self->write_pos;
  if (self->read_pos == 0)
    to_write -= 1;
  if (to_write > *size)
    to_write = *size;
  memcpy(&self->buff[self->write_pos], *buff, to_write);
  *buff = &((*buff)[to_write]);
  *size -= to_write;
  self->write_pos =
    (unsigned int)((self->size + self->write_pos + to_write) % self->size);
}

static void	write_begin(t_circular_buffer *self,
			       const char **buff,
			       size_t *size)
{
  size_t	to_write;

  to_write = self->read_pos - self->write_pos - 1;
  if (to_write > *size)
    to_write = *size;
  memcpy(&self->buff[self->write_pos], *buff, to_write);
  *size -= to_write;
  self->write_pos += to_write;
}

ssize_t		circular_buffer_write(t_circular_buffer *self,
					     const char *buff,
					     size_t size)
{
  size_t	to_write;

  to_write = size;
  if (self->write_pos >= self->read_pos)
    write_end(self, &buff, &to_write);
  if (to_write > 0 && self->write_pos < self->read_pos)
    write_begin(self, &buff, &to_write);
  if (to_write == size)
    return (-1);
  else
    return (size - to_write);
}