/*
** discard_data.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/discard_data.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:50:46 2017 Anas Buyumad
** Last update Mon May 29 19:50:47 2017 Anas Buyumad
*/

#include	<memory.h>
#include	"common/ring_buffer.h"

void		ring_buffer_discard_data(t_ring_buffer *buffer)
{
  memset(buffer->buffer, 0, RING_BUFFER_SIZE);
  buffer->head = buffer->buffer;
  buffer->tail = buffer->buffer;
}