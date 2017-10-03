/*
** is_full.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/is_full.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 19:42:24 2017 Antoine FORET
** Last update Wed May 31 19:42:24 2017 Antoine FORET
*/

#include	"circular_buffer.h"

bool		circular_buffer_is_full(t_circular_buffer *self)
{
  return (self->get_remaining_space(self) == 0);
}