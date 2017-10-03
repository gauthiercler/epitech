/*
** get_remaining_size.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/get_remaining_size.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 16:45:03 2017 Antoine FORET
** Last update Wed May 31 16:45:03 2017 Antoine FORET
*/

#include	"circular_buffer.h"

size_t		circular_buffer_get_remaining_space(t_circular_buffer *self)
{
  return (self->size - self->get_remaining_read(self) - 1);
}