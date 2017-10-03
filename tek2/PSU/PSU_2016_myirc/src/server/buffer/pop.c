/*
** pop.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/buffer/pop.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 23:07:09 2017 Anas Buyumad
** Last update Thu May 25 23:07:11 2017 Anas Buyumad
*/

#include		<memory.h>
#include		<stdbool.h>
#include		"server/structures.h"

bool			buffer_pop(t_cmd_buffer *buffer,
				       t_command *command)
{
  t_command		*next;

  if (buffer->tail == buffer->head)
    return (false);
  next = buffer->tail + 1;
  if (next >= buffer->buffer + COMMAND_BUFFER_SIZE)
    next = buffer->buffer;
  memcpy(command, buffer->tail, sizeof(t_command));
  buffer->tail = next;
  return (true);
}