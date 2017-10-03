/*
** skip.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/skip.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 03 15:01:26 2017 Antoine FORET
** Last update Sat Jun 03 15:01:26 2017 Antoine FORET
*/

#include	"circular_buffer.h"

void		circular_buffer_skip(t_circular_buffer *self, size_t to_skip)
{
  size_t	remaining;

  remaining = self->get_remaining_read(self);
  if (remaining < to_skip)
    to_skip = remaining;
  self->read_pos =
    (unsigned int)((self->size + self->read_pos + to_skip) % self->size);
}