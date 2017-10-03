/*
** destroy.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 16:38:26 2017 Antoine FORET
** Last update Wed May 31 16:38:26 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"circular_buffer.h"

void		circular_buffer_destroy(t_circular_buffer *self)
{
  if (self->buff != NULL)
    free(self->buff);
  free(self);
}