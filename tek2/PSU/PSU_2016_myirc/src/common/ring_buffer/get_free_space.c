/*
** get_free_space.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/get_free_space.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:31:12 2017 Anas Buyumad
** Last update Mon May 29 19:31:13 2017 Anas Buyumad
*/

#include	"common/ring_buffer.h"

static bool	is_at_end(t_ring_buffer *buffer, uint8_t *pointer)
{
  uint8_t	*next;

  next = pointer + 1;
  if (next >= buffer->buffer + RING_BUFFER_SIZE)
    next = buffer->buffer;
  if (next == buffer->tail)
    return (true);
  return (false);
}

uint16_t	get_ring_buffer_free_space(t_ring_buffer *buffer)
{
  uint16_t 	free_space;
  uint8_t 	*pointer;

  free_space = 0;
  pointer = buffer->head;
  if (ring_buffer_is_empty(buffer))
    return (RING_BUFFER_SIZE - 1);
  else if (ring_buffer_is_full(buffer))
    return (free_space);
  while (!is_at_end(buffer, pointer))
  {
    free_space += 1;
    pointer += 1;
  }
  return (free_space);
}