/*
** get_input_size.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/get_input_size.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:57:08 2017 Anas Buyumad
** Last update Mon May 29 19:57:08 2017 Anas Buyumad
*/

#include	"common/ring_buffer.h"

static uint8_t	*next_pointer(t_ring_buffer *buffer, uint8_t *pointer)
{
  uint8_t 	*next;

  next = pointer + 1;
  if (next >= buffer->buffer + RING_BUFFER_SIZE)
    next = buffer->buffer;
  return (next);
}

static bool	peek_linefeed(t_ring_buffer *buffer, uint8_t *pointer)
{
  uint8_t 	*next;

  next = next_pointer(buffer, pointer);
  if (next != buffer->head && *next == LINE_FEED)
    return (true);
  return (false);
}

int16_t		ring_buffer_get_input_size(t_ring_buffer *buffer)
{
  int16_t	input_size;
  uint8_t 	*pointer;
  bool		is_valid;

  input_size = 0;
  is_valid = false;
  pointer = buffer->tail;
  if (ring_buffer_is_empty(buffer))
    return (input_size);
  while (pointer != buffer->head)
  {
    if (*pointer == CARRIAGE_RETURN && peek_linefeed(buffer, pointer))
    {
      input_size += 2;
      is_valid = true;
      break ;
    }
    input_size += 1;
    pointer = next_pointer(buffer, pointer);
  }
  if (!is_valid && ring_buffer_is_full(buffer))
    return (INVALID_INPUT);
  return (input_size);
}