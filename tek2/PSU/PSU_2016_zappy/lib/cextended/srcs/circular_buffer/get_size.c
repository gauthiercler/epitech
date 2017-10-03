/*
** get_size.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/get_size.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 16:39:50 2017 Antoine FORET
** Last update Wed May 31 16:39:50 2017 Antoine FORET
*/

#include	"circular_buffer.h"

size_t		circular_buffer_get_size(t_circular_buffer *self)
{
  return (self->size - 1);
}