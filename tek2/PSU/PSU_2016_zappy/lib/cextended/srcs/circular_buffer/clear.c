/*
** clear.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/clear.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 02 14:27:06 2017 Antoine FORET
** Last update Fri Jun 02 14:27:06 2017 Antoine FORET
*/

#include	"circular_buffer.h"

void		circular_buffer_clear(t_circular_buffer *self)
{
  self->write_pos = 0;
  self->read_pos = 0;
}