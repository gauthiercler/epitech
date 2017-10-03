/*
** is_empty.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/buffer/is_empty.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:52:06 2017 Anas Buyumad
** Last update Sun May 28 01:52:06 2017 Anas Buyumad
*/

#include		"server/structures.h"

bool			buffer_is_empty(t_cmd_buffer *buffer)
{
  if (buffer->tail == buffer->head)
    return (true);
  return (false);
}