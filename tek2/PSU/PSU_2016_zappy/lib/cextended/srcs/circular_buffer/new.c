/*
** new.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/srcs/circular_buffer/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 16:24:54 2017 Antoine FORET
** Last update Wed May 31 16:24:54 2017 Antoine FORET
*/

#include		<malloc.h>
#include		<string.h>
#include		"circular_buffer.h"

static void		circular_buffer_methods(t_circular_buffer *self)
{
  self->get_size = circular_buffer_get_size;
  self->get_remaining_read = circular_buffer_get_remaining_read;
  self->get_remaining_space = circular_buffer_get_remaining_space;
  self->is_full = circular_buffer_is_full;
  self->get_pos = circular_buffer_get_pos;
  self->clear = circular_buffer_clear;
  self->skip = circular_buffer_skip;
  self->write = circular_buffer_write;
  self->read = circular_buffer_read;
  self->size_before = circular_buffer_size_before;
  self->destroy = circular_buffer_destroy;
}

static bool		circular_buffer_init(t_circular_buffer *self,
						size_t size)
{
  self->buff = malloc(sizeof(char) * (size + 1));
  if (self->buff == NULL)
    return (false);
  self->size = size + 1;
  self->write_pos = 0;
  self->read_pos = 0;
  memset(self->buff, 0, self->size);
  return (true);
}

t_circular_buffer	*new_circular_buffer(size_t size)
{
  t_circular_buffer	*self;

  self = malloc(sizeof(t_circular_buffer));
  if (self == NULL)
    return (NULL);
  if (!circular_buffer_init(self, size))
  {
    free(self);
    return (NULL);
  }
  circular_buffer_methods(self);
  return (self);
}