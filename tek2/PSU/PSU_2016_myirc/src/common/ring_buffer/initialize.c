/*
** initialize.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/ring_buffer/initialize.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:25:09 2017 Anas Buyumad
** Last update Mon May 29 19:25:09 2017 Anas Buyumad
*/

#include	"common/ring_buffer.h"

void		initialize_ring_buffer(t_ring_buffer *buffer)
{
  buffer->head = buffer->buffer;
  buffer->tail = buffer->buffer;
}