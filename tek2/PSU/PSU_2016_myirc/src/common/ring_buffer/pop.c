/*
** pop.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/pop.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:37:43 2017 Anas Buyumad
** Last update Mon May 29 19:37:43 2017 Anas Buyumad
*/

#include	"common/ring_buffer.h"

bool		ring_buffer_pop(t_ring_buffer *buffer, uint8_t *byte)
{
  uint8_t 	*next;

  if (buffer->tail == buffer->head)
    return (false);
  next = buffer->tail + 1;
  if (next >= buffer->buffer + RING_BUFFER_SIZE)
    next = buffer->buffer;
  *byte = *buffer->tail;
  *buffer->tail = 0;
  buffer->tail = next;
  return (true);
}