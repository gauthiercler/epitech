/*
** read.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/read.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 19:43:05 2017 Antoine FORET
** Last update Wed May 31 19:43:05 2017 Antoine FORET
*/

#include	<string.h>
#include	"circular_buffer.h"

static void	read_end(t_circular_buffer *self, char **buff, size_t *size)
{
  size_t	to_read;

  to_read = self->size - self->read_pos;
  if (to_read > *size)
    to_read = *size;
  memcpy(*buff, &self->buff[self->read_pos], to_read);
  *buff = &((*buff)[to_read]);
  *size -= to_read;
  self->read_pos =
    (unsigned int)((self->size + self->read_pos + to_read) % self->size);
}

static void	read_begin(t_circular_buffer *self, char **buff, size_t *size)
{
  size_t	to_read;

  to_read = self->write_pos - self->read_pos;
  if (to_read > *size)
    to_read = *size;
  memcpy(*buff, &self->buff[self->read_pos], to_read);
  *buff = &((*buff)[to_read]);
  *size -= to_read;
  self->read_pos += to_read;
}

ssize_t		circular_buffer_read(t_circular_buffer *self,
					    char *buff,
					    size_t size)
{
  size_t	to_read;

  to_read = size;
  if (self->read_pos > self->write_pos)
    read_end(self, &buff, &to_read);
  if (size > 0)
    read_begin(self, &buff, &to_read);
  if (to_read == size)
    return (-1);
  else
    return ((ssize_t)(size - to_read));
}