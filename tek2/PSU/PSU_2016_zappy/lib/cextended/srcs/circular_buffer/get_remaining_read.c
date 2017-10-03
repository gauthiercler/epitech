/*
** get_remaining_read.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/get_remaining_read.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 19:39:51 2017 Antoine FORET
** Last update Wed May 31 19:39:51 2017 Antoine FORET
*/

#include	"circular_buffer.h"

size_t		circular_buffer_get_remaining_read(t_circular_buffer *self)
{
  if (self->read_pos > self->write_pos)
    return (self->size - self->read_pos + self->write_pos);
  else
    return ((size_t)(self->write_pos - self->read_pos));
}