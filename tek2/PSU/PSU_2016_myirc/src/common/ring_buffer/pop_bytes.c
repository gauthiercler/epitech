/*
** pop_bytes.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/pop_bytes.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue May 30 14:06:11 2017 Anas Buyumad
** Last update Tue May 30 14:06:11 2017 Anas Buyumad
*/

#include	<memory.h>
#include	"common/ring_buffer.h"

bool		pop_bytes(t_ring_buffer *buffer, uint16_t nb_bytes,
			      char bytes[RING_BUFFER_SIZE])
{
  size_t	iterator;

  iterator = 0;
  memset(bytes, 0, RING_BUFFER_SIZE);
  while (iterator < nb_bytes)
  {
    if (!ring_buffer_pop(buffer, (uint8_t *)&bytes[iterator]))
      return (false);
    iterator += 1;
  }
  return (true);
}