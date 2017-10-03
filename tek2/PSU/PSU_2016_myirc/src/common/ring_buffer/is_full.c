/*
** is_full.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/is_full.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:31:15 2017 Anas Buyumad
** Last update Mon May 29 19:31:16 2017 Anas Buyumad
*/

#include	"common/ring_buffer.h"

bool		ring_buffer_is_full(t_ring_buffer *buffer)
{
  uint8_t 	*next;

  next = buffer->head + 1;
  if (next >= buffer->buffer + RING_BUFFER_SIZE)
    next = buffer->buffer;
  if (next == buffer->tail)
    return (true);
  return (false);
}