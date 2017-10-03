/*
** size_before.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/circular_buffer/size_before.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 10:21:40 2017 Antoine FORET
** Last update Fri Jun 30 10:21:40 2017 Antoine FORET
*/

#include	"circular_buffer.h"

ssize_t		circular_buffer_size_before(t_circular_buffer *self,
						   char token)
{
  size_t	remaining;
  size_t	read;

  remaining = self->get_remaining_read(self);
  read = 0;
  while (remaining > 0)
  {
    read += 1;
    remaining -= 1;
    if (self->buff[(self->read_pos + read) % self->size] == token)
      return (read);
  }
  return (-1);
}