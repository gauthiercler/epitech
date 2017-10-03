/*
** push.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/buffer/push.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 23:07:14 2017 Anas Buyumad
** Last update Thu May 25 23:07:14 2017 Anas Buyumad
*/

#include		<memory.h>
#include		<stdbool.h>
#include		"server/structures.h"

bool			buffer_push(t_cmd_buffer *buffer,
					t_command *command)
{
  t_command		*next;

  next = buffer->head + 1;
  if (next >= buffer->buffer + COMMAND_BUFFER_SIZE)
    next = buffer->buffer;
  if (next == buffer->tail)
    return (false);
  memcpy(buffer->head, command, sizeof(t_command));
  buffer->head = next;
  return (true);
}