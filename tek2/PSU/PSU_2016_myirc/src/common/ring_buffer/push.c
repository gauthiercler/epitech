/*
** push.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/push.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:26:51 2017 Anas Buyumad
** Last update Mon May 29 19:26:52 2017 Anas Buyumad
*/

#include	"common/ring_buffer.h"

bool		ring_buffer_push(t_ring_buffer *buffer, uint8_t byte)
{
  uint8_t 	*next;

  next = buffer->head + 1;
  if (next >= buffer->buffer + RING_BUFFER_SIZE)
    next = buffer->buffer;
  if (next == buffer->tail)
    return (false);
  *buffer->head = byte;
  buffer->head = next;
  return (true);
}