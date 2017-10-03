/*
** is_full.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/buffer/is_full.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:53:26 2017 Anas Buyumad
** Last update Sun May 28 01:53:26 2017 Anas Buyumad
*/

#include		"server/structures.h"

bool			buffer_is_full(t_cmd_buffer *buffer)
{
  t_command		*next;

  next = buffer->head + 1;
  if (next >= buffer->buffer + COMMAND_BUFFER_SIZE)
    next = buffer->buffer;
  if (next == buffer->tail)
    return (true);
  return (false);
}