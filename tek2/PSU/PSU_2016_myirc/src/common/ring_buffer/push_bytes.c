/*
** push_bytes.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/push_bytes.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:50:18 2017 Anas Buyumad
** Last update Mon May 29 19:50:18 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"common/ring_buffer.h"

bool		push_bytes(t_ring_buffer *buffer, char *bytes,
			       uint16_t size)
{
  uint16_t	free_space;
  size_t	iterator;

  iterator = 0;
  free_space = get_ring_buffer_free_space(buffer);
  if (free_space < size)
    return (false);
  while (iterator < size)
  {
    if (!ring_buffer_push(buffer, (uint8_t)bytes[iterator]))
      return (false);
    iterator += 1;
  }
  return (true);
}