/*
** is_empty.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/is_empty.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:31:18 2017 Anas Buyumad
** Last update Mon May 29 19:31:18 2017 Anas Buyumad
*/

#include	"common/ring_buffer.h"

bool		ring_buffer_is_empty(t_ring_buffer *buffer)
{
  if (buffer->tail == buffer->head)
    return (true);
  return (false);
}